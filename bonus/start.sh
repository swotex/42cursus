#sh ./install.sh

# --- docker part ---

version_minimale="20.10.5"
version_installee=$(docker --version | awk '{print $3}' | tr -d ',')

if [ "$(printf '%s\n' "$version_minimale" "$version_installee" | sort -V | head -n1)" != "$version_minimale" ]; then
    echo "Docker is too old (version $version_installee < $version_minimale)"
    exit 1
fi

sudo docker info > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "\n\033[1;34m🚀 Run docker deamon\033[0m\n"
    sudo dockerd > /dev/null 2>&1 &
    echo "⏳ Waiting for the docker daemon to start..."
    while ! sudo docker info >/dev/null 2>&1; do
        sleep 1
    done
fi

echo "\n\033[1;35m✅ Docker daemon is ready !\033[0m"

# --- k3s cluster ---

echo "\n\033[1;34m🚀 Create cluster\033[0m\n"
sudo k3d cluster create XCluster \
  --servers 1 --agents 2 \
  --api-port 6550 


# --- Creating namespace ---
sudo kubectl create namespace argocd
sudo kubectl create namespace gitlab

# --- Install GitLab ---
echo "\n\033[1;34m🚀 Install gitlab\033[0m\n"
sudo helm repo add gitlab https://charts.gitlab.io/
sudo helm repo update

sudo helm upgrade --install gitlab gitlab/gitlab \
  --namespace gitlab \
  -f confs/gitlab-deployement.yaml

sudo kubectl apply -n gitlab -f confs/gitlab-ingress.yaml


# --- ArgoCD deployement ---

echo "\n\033[1;34m🚀 Deploying argoCD\033[0m\n"
sudo kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
#sudo kubectl -n argocd patch svc argocd-server \
#  -p '{"spec": {"type": "LoadBalancer"}}'


# --- Update hosts ---
sudo tee -a /etc/hosts <<EOF
172.17.0.1 gitlab.local
127.0.0.1 argocd.local
EOF


echo "⏳ Waiting for ArgoCD to be ready..."
#kubectl -n gitlab rollout status deployment/gitlab-webservice-default --timeout=600s
#kubectl -n argocd rollout status deployment/argocd-server --timeout=120s

sudo kubectl wait deployment argocd-server \
  -n argocd \
  --for=condition=Available=True \
  --timeout=120s

echo "⏳ Waiting for GitLab to be ready..."
sudo kubectl wait deployment gitlab-webservice-default \
  -n gitlab \
  --for=condition=Available=True \
  --timeout=180s

# --- Retrieve GitLab root password and generate a private token
GITLAB_ROOT_PWD=$(sudo kubectl -n gitlab get secret gitlab-gitlab-initial-root-password -o jsonpath="{.data.password}" | base64 -d)
echo "password root gitlab: " ${GITLAB_ROOT_PWD}
#GITLAB_TOKEN=$(curl -s --request POST "http://root:${GITLAB_ROOT_PWD}@gitlab.local/api/v4/session" \
#  --data "login=root&password=${GITLAB_ROOT_PWD}" | jq -r .private_token)


# --- Create a new project in GitLab ---
#PROJECT_JSON=$(curl -s --header "PRIVATE-TOKEN: ${GITLAB_TOKEN}" \
#  --data "name=njegat_iot_website&namespace_id=1" \
#  http://gitlab.local/api/v4/projects)
#REPO_URL=$(jq -r .http_url_to_repo <<<"${PROJECT_JSON}")


# 10. Initialize repository with sample k8s manifests
#git clone ${REPO_URL} app_repo
#git -C app_repo checkout -b main || true
#mkdir -p app_repo/k8s
#cat <<EOF >app_repo/k8s/deployment.yaml
#apiVersion: apps/v1
#kind: Deployment
#metadata:
#  name: njegat_iot_website
#  namespace: dev
#spec:
#  replicas: 1
#  selector:
#    matchLabels:
#      app: njegat_iot_website
#  template:
#    metadata:
#      labels:
#        app: njegat_iot_website
#    spec:
#      containers:
#      - name: nginx
#        image: nginx:alpine
#        ports:
#        - containerPort: 80
#EOF
#cat <<EOF >app_repo/k8s/service.yaml
#apiVersion: v1
#kind: Service
#metadata:
#  name: njegat_iot_website
#  namespace: dev
#spec:
#  selector:
#    app: njegat_iot_website
#  ports:
#  - port: 80
#    targetPort: 80
#EOF
#git -C app_repo add .
#git -C app_repo commit -m "Initial k8s manifests"
#git -C app_repo push origin main

# Deploy App git in argoCD
# sudo kubectl apply -f ./confs/app.yaml en attente

# --- Get ArgoCD credentials ---

PWD_ARGOCD=$(sudo kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d)
echo "\n\033[1;34m🔑 ArgoCD credencial\033[0m"
echo "\033[1;35mUser:\033[0m"
echo "admin"
echo "\033[1;35mPassword:\033[0m"
echo "$PWD_ARGOCD\n"

# --- Print ArgoCD/App link ---
ARGO_IP=$(sudo kubectl -n argocd get svc argocd-server -o jsonpath='{.status.loadBalancer.ingress[0].ip}')
#echo "ArgoCD: https://$ARGO_IP - App: http://$ARGO_IP:1212"
#echo "----- or -----"
echo "ArgoCD: https://localhost:8080 - App: http://localhost:8888"

sudo kubectl port-forward svc/argocd-server -n argocd 8080:80