FROM alpine:3.20

RUN apk update && \
	apk add --no-cache php83 php83-mysqli php83-session wget

RUN mkdir -p /var/www/html && \
	wget https://www.adminer.org/latest.php -O /var/www/html/index.php

WORKDIR /var/www/html

EXPOSE 8080

CMD ["php83", "-S", "0.0.0.0:8080", "-t", "/var/www/html"]