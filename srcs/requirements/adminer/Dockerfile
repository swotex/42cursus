FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y php-common php php-mysql wget;

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O index.php

ENTRYPOINT ["php", "-S", "0.0.0.0:8000"]
