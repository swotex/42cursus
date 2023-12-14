FROM debian:bullseye

ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG DB_NAME

RUN apt-get update -y && \
    apt-get install -y mariadb-server && \
    /etc/init.d/mariadb start && \
    mysql -u root -h localhost -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';\
                      CREATE DATABASE IF NOT EXISTS ${DB_NAME};\
                      GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${MYSQL_USER}'@'%';\
                      FLUSH PRIVILEGES;\
                      ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';";
    

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["mysqld_safe"]
