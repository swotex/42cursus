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
