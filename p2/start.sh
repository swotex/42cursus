vagrant up

sleep 3

grep -v '[[:space:]]app1\.com' /etc/hosts > /tmp/hosts
grep -v '[[:space:]]app2\.com' /tmp/hosts > /tmp/hosts2
grep -v '[[:space:]]app2\.com' /tmp/hosts2 > /tmp/hosts
echo "192.168.56.110  app1.com" >> /tmp/hosts
echo "192.168.56.110  app2.com" >> /tmp/hosts
echo "192.168.56.110  app3.com" >> /tmp/hosts
sudo cp /tmp/hosts /etc/hosts

APP1_URL="http://app1.com"
APP2_URL="http://app2.com"
APP3_URL="http://app3.com"

app1_up=false
app2_up=false
app3_up=false

echo " ---"

echo "$APP1_URL Waiting..."
echo "$APP2_URL Waiting..."
echo "$APP3_URL Waiting..."

while [ "$app1_up" = false ] || [ "$app2_up" = false ] || [ "$app3_up" = false ]; do

    tput cuu 3

    if curl -s --head --request GET "$APP1_URL" | grep "200 OK" > /dev/null; then
        app1_up=true
        tput el
        echo "✅ $APP1_URL is UP"
    else
        echo "❌ $APP1_URL is DOWN"
    fi

    if curl -s --head --request GET "$APP2_URL" | grep "200 OK" > /dev/null; then
        app2_up=true
        tput el
        echo "✅ $APP2_URL is UP"
    else
        echo "❌ $APP2_URL is DOWN"
    fi

    if curl -s --head --request GET "$APP3_URL" | grep "200 OK" > /dev/null; then
        app3_up=true
        tput el
        echo "✅ $APP3_URL is UP"
    else
        echo "❌ $APP3_URL is DOWN"
    fi

    if [ "$app1_up" != true ] && [ "$app2_up" != true ] && [ "$app3_up" != true ]; then
        sleep 3
    fi

done