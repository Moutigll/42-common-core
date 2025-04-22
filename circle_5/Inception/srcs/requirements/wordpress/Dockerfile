FROM alpine:3.18

RUN apk update && apk add --no-cache \
	php81 \
	php81-fpm \
	php81-mysqli \
	php81-session \
	php81-mbstring \
	php81-json \
	php81-opcache \
	php81-curl \
	php81-dom \
	php81-exif \
	php81-fileinfo \
	php81-iconv \
	php81-pecl-imagick \
	php81-xml \
	php81-xmlreader \
	php81-xmlwriter \
	php81-tokenizer \
	php81-common \
	php81-gd \
	php81-pdo \
	php81-pdo_mysql \
	php81-openssl \
	php81-ctype \
	php81-simplexml \
	php81-phar \
	php81-zlib \
	php81-pecl-redis \
	curl \
	bash \
	sudo \
	tar \
	wget \
	less \
	redis \
	openrc \
	shadow \
	openssl

RUN sed -i 's/^;daemonize = yes/daemonize = no/' /etc/php81/php-fpm.conf && \
	sed -i 's|^listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|' /etc/php81/php-fpm.d/www.conf

RUN adduser -D -u 83 -G www-data www-data

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html
RUN mkdir /run/php

COPY ./create_wp.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wp.sh

COPY ./www.conf /etc/php81/php-fpm.d/

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/create_wp.sh"]

RUN chown -R nobody:nogroup /var/www/html

CMD ["php-fpm81", "-F"]

