FROM debian:bullseye

ARG FTP_USER
ARG FTP_PASS

RUN apt-get update -y && \
    apt-get install -y vsftpd;

COPY ./conf/vsftpd.conf /etc/vsftpd.conf

RUN useradd -m -d "/var/ftp/${FTP_USER}" -s /bin/bash "${FTP_USER}"
RUN echo "${FTP_USER}:${FTP_PASS}" | chpasswd

#RUN chmod 1777 /var/njegatwp

COPY ./tools/start.sh ./start.sh

ENTRYPOINT ["/bin/bash", "start.sh"]

#ENTRYPOINT ["/usr/sbin/vsftpd"]
