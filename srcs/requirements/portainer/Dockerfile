FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y wget tar;

RUN wget https://github.com/portainer/portainer/releases/download/2.19.1/portainer-2.19.1-linux-amd64.tar.gz -O ptrner.tar.gz

RUN tar -xf ptrner.tar.gz;

RUN chmod 777 portainer/portainer

ENTRYPOINT ["./portainer/portainer"]
