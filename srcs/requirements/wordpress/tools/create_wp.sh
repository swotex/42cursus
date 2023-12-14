cd /var/njegatwp;

if [ ! -e "wp-config.php" ]; then

    wp core download --allow-root;

    wp core config --allow-root --dbhost=${MYSQL_HOST} --dbname=${DB_NAME} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD};

    wp core install --allow-root --skip-email --url=${DOMAIN_NAME} --title=${WP_TITLE} --admin_name=${WP_ADMIN} --admin_password=${WP_PASS} --admin_email=${WP_MAIL};

    wp user create --allow-root ${WP_USER} ${WP_USERMAIL} --user_pass=${WP_USERPASS}

    wp theme install --allow-root twentyseventeen --activate;

    wp plugin install --allow-root redis-cache --activate

    wp config set --allow-root WP_REDIS_HOST 'redis'

    wp redis enable --allow-root

    mkdir /run/php

fi

php-fpm7.4 -F
