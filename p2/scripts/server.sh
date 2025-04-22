curl -sfL https://get.k3s.io | INSTALL_K3S_EXEC="--node-ip=192.168.56.110" sh -

echo "⏳ Waiting k3s startup..."
until kubectl get nodes &> /dev/null; do
  sleep 2
done

mkdir -p /opt/html/app1
cp -r /vagrant_html/app1/* /opt/html/app1/
chmod -R 755 /opt/html/app1

mkdir -p /opt/html/app3
cp -r /vagrant_html/app3/* /opt/html/app3/
chmod -R 755 /opt/html/app3

echo "✅ K3S ready applying conf file..."
kubectl apply -f /vagrant_data/