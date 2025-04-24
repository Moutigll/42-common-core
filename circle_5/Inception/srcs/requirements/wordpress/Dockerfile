FROM alpine:3.20

RUN apk update && \
	apk add --no-cache \
		php82 \
		php82-cgi \
		php82-fpm \
		php82-mysqli \
		curl \
		wget

RUN sed -i 's/^;daemonize = yes/daemonize = no/' /etc/php82/php-fpm.conf && \
	sed -i 's|^listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|' /etc/php82/php-fpm.d/www.conf

RUN adduser -D -u 83 -G www-data www-data

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html
RUN mkdir /run/php

COPY ./create_wp.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wp.sh

COPY ./www.conf /etc/php82/php-fpm.d/

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/create_wp.sh"]

RUN chown -R nobody:nogroup /var/www/html

CMD ["php-fpm82", "-F"]

