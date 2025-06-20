sh ./install.sh

# --- docker part ---

version_minimale="20.10.5"
version_installee=$(docker --version | awk '{print $3}' | tr -d ',')

if [ "$(printf '%s\n' "$version_minimale" "$version_installee" | sort -V | head -n1)" != "$version_minimale" ]; then
    echo -e "\033[1;31mDocker is too old (version $version_installee < $version_minimale)\033[0m"
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

echo -e "\n\033[1;35m✅ Docker daemon is ready !\033[0m"

# --- k3s cluster ---

echo -e "\n\033[1;34m🚀 Create cluster\033[0m\n"
sudo k3d cluster create XCluster \
  --servers 1 --agents 2 \
  --api-port 6550 \
  -p "8080:80@loadbalancer" \
  -p "8443:443@loadbalancer" \
  -p "8888:1212@loadbalancer"

# --- ArgoCD deployement ---

echo -e "\n\033[1;34m🚀 Deploying argoCD\033[0m\n"
sudo kubectl create namespace argocd
sudo kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
sudo kubectl -n argocd patch svc argocd-server \
  -p '{"spec": {"type": "LoadBalancer"}}'

echo "⏳ Waiting for ArgoCD to be ready..."
sudo kubectl wait deployment argocd-server \
  -n argocd \
  --for=condition=Available=True \
  --timeout=120s

# Deploy App github
sudo kubectl apply -f ./confs/app.yaml

# --- Get ArgoCD credentials ---

PWD_ARGOCD=$(sudo kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d)
echo -e "\n\033[1;34m🔑 ArgoCD credencial\033[0m"
echo -e "\033[1;35mUser:\033[0m"
echo "admin"
echo -e "\033[1;35mPassword:\033[0m"
echo "$PWD_ARGOCD\n"

# --- Print ArgoCD/App link ---
ARGO_IP=$(sudo kubectl -n argocd get svc argocd-server -o jsonpath='{.status.loadBalancer.ingress[0].ip}')
echo "ArgoCD: https://$ARGO_IP - App: http://$ARGO_IP:1212"
echo "----- or -----"
echo "ArgoCD: https://localhost:8443 - App: http://localhost:8888"

