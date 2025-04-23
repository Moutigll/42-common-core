FROM alpine:3.20

RUN apk update && \
	apk add --no-cache mariadb mariadb-client && \
	mkdir -p /run/mysqld && \
	chown -R mysql:mysql /run/mysqld /var/lib/mysql

EXPOSE 3306

COPY my.cnf /etc/my.cnf
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

RUN chown -R mysql:mysql /var/lib/mysql

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

