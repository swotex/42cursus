# Need k3d, docker ^20.10.5, kubectl, curl

echo -e "\033[1;33mInstall dependancies...\033[0m"
sudo apt install docker.io curl

# install k3d
echo -e "\033[1;33mInstall k3d...\033[0m"
curl -s https://raw.githubusercontent.com/k3d-io/k3d/main/install.sh | bash

# install kubectl + add in path
echo -e "\033[1;33mInstall kubectl...\033[0m"
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
sudo install -o root -g root -m 0755 kubectl /usr/local/bin/kubectl
rm -rf ./kubectl