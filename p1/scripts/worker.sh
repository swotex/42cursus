# curl -sfL https://get.k3s.io | sh -s - agent --token-file /vagrant_data/node-token --server 192.168.56.110:6443

#while [ ! -f /vagrant_data/node-token ]; do
#    echo "En attente du token depuis le serveur..."
#    sleep 2
#done

# Lire le token
#TOKEN=$(cat /vagrant_data/node-token)

# Lancer K3s en mode agent
#curl -sfL https://get.k3s.io | K3S_URL=https://192.168.56.110:6443 K3S_TOKEN=$TOKEN sh -




token_file="/vagrant_data/node-token"

while [ ! -f $token_file ]; do
    echo "Waiting token from server..."
    sleep 2
done

curl -sfL https://get.k3s.io | \
K3S_TOKEN_FILE=$token_file \
K3S_URL=https://192.168.56.110:6443 \
INSTALL_K3S_EXEC="--node-ip=192.168.56.111" \
sh -
