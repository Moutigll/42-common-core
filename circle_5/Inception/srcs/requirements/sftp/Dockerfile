FROM alpine:3.20

ARG FTP_USER
ARG FTP_PASSWORD

RUN apk update && \
	apk add openssh && \
	adduser -D "$FTP_USER" && \
	echo "$FTP_USER:$FTP_PASSWORD" | chpasswd && \
	mkdir -p /home/"$FTP_USER"/upload && \
	chown -R "$FTP_USER":"$FTP_USER" /home/"$FTP_USER" && \
	chmod 700 /home/"$FTP_USER" && \
	ssh-keygen -A

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 22

CMD ["/entrypoint.sh"]