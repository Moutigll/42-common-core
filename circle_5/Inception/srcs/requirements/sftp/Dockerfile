FROM alpine:latest

RUN apk update && \
	apk add openssh && \
	adduser -D ftpuser && \
	echo "ftpuser:ftppassword" | chpasswd && \
	mkdir -p /home/ftpuser/upload && \
	chown -R ftpuser:ftpuser /home/ftpuser && \
	chmod 700 /home/ftpuser && \
	ssh-keygen -A

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 22

CMD ["/entrypoint.sh"]
