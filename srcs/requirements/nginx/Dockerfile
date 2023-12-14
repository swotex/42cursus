FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install --no-install-recommends -y nginx openssl && \
    openssl req -x509 -nodes -subj /C=FR -newkey rsa:2048 -keyout /etc/ssl/private/njegat-selfsigned.key -out /etc/ssl/certs/njegat-selfsigned.crt ;

COPY ./conf/42Web /etc/nginx/sites-enabled/42Web
COPY ./tools/static.html /var/njegatwp/static.html

ENTRYPOINT ["nginx", "-g", "daemon off;"]
