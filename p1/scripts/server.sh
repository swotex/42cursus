curl -sfL https://get.k3s.io | INSTALL_K3S_EXEC="--node-ip=192.168.56.110" sh -

token_file="/var/lib/rancher/k3s/server/node-token"

while [ ! -f "$token_file" ]; do
    echo "Waiting for cluster token creation"
    sleep 1
done
cat $token_file > /vagrant_data/node-token