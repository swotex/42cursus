



sleep 5;




/etc/init.d/mariadb start && \
mysql -u root -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';\
                      CREATE DATABASE IF NOT EXISTS ${DB_NAME};\
                      GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';\
                      FLUSH PRIVILEGES;";



mysqld_safe 

