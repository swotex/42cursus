FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y wget mariadb-client php7.4-fpm php-common php-mysql libapache2-mod-php php-cli php-tokenizer && \
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp

COPY ./tools/create_wp.sh /tmp/create_wp.sh
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN chmod +x /tmp/create_wp.sh

ENTRYPOINT ["/bin/bash", "/tmp/create_wp.sh"]
