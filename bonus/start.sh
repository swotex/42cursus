#sh ./install.sh

# --- docker part ---

version_minimale="20.10.5"
version_installee=$(docker --version | awk '{print $3}' | tr -d ',')

if [ "$(printf '%s\n' "$version_minimale" "$version_installee" | sort -V | head -n1)" != "$version_minimale" ]; then
    echo -e "\033[1;31mDocker is too old (version $version_installee < $version_minimale)\033[0m"
    exit 1
fi

sudo docker info > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "\n\033[1;34m🚀 Run docker deamon\033[0m\n"
    sudo dockerd > /dev/null 2>&1 &
    echo "⏳ Waiting for the docker daemon to start..."
    while ! sudo docker info >/dev/null 2>&1; do
        sleep 1
    done
fi

echo -e "\n\033[1;35m✅ Docker daemon is ready !\033[0m"

# --- k3s cluster ---

echo -e "\n\033[1;34m🚀 Create cluster\033[0m\n"
sudo k3d cluster create XCluster \
  --servers 1 --agents 2 \
  --api-port 6550


# --- Creating namespace ---
sudo kubectl create namespace argocd
sudo kubectl create namespace gitlab

# --- Install GitLab ---
echo -e "\n\033[1;34m🚀 Install gitlab\033[0m\n"
sudo helm repo add gitlab https://charts.gitlab.io/
sudo helm repo update

sudo helm upgrade --install gitlab gitlab/gitlab \
  --namespace gitlab \
  -f confs/gitlab-deployement.yaml

sudo kubectl apply -n gitlab -f confs/gitlab-ingress.yaml


# --- ArgoCD deployement ---

echo -e "\n\033[1;34m🚀 Deploying argoCD\033[0m\n"
sudo kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
#sudo kubectl -n argocd patch svc argocd-server \
#  -p '{"spec": {"type": "LoadBalancer"}}'


# --- Update hosts ---
sudo tee -a /etc/hosts <<EOF
172.18.0.2 gitlab.local
127.0.0.1 argocd.local
EOF


echo "⏳ Waiting for ArgoCD to be ready..."
sudo kubectl wait deployment argocd-server \
  -n argocd \
  --for=condition=Available=True \
  --timeout=120s

echo "⏳ Waiting for GitLab to be ready..."
sudo kubectl wait deployment gitlab-webservice-default \
  -n gitlab \
  --for=condition=Available=True \
  --timeout=240s

# --- Retrieve GitLab root password and generate a private token
GITLAB_ROOT_PWD=$(sudo kubectl -n gitlab get secret gitlab-gitlab-initial-root-password -o jsonpath="{.data.password}" | base64 -d)
echo "password root gitlab: " ${GITLAB_ROOT_PWD}
#GITLAB_TOKEN=$(curl -s --request POST "http://root:${GITLAB_ROOT_PWD}@gitlab.local/api/v4/session" \
#  --data "login=root&password=${GITLAB_ROOT_PWD}" | jq -r .private_token)


# --- Get ArgoCD credentials ---

PWD_ARGOCD=$(sudo kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d)
echo -e "\n\033[1;34m🔑 ArgoCD credencial\033[0m"
echo -e "\033[1;35mUser:\033[0m"
echo "admin"
echo -e "\033[1;35mPassword:\033[0m"
echo "$PWD_ARGOCD\n"

# --- Print ArgoCD/App link ---
ARGO_IP=$(sudo kubectl -n argocd get svc argocd-server -o jsonpath='{.status.loadBalancer.ingress[0].ip}')
#echo "ArgoCD: https://$ARGO_IP - App: http://$ARGO_IP:1212"
#echo "----- or -----"
echo "ArgoCD: https://localhost:8080 - App: http://localhost:8888"

sudo kubectl port-forward svc/argocd-server -n argocd 8080:80