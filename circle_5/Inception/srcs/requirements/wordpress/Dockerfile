FROM alpine:3.20

RUN apk update && \
    apk add --no-cache \
        php82-cli \
		php82-phar \
        php82-fpm \
		php82-mbstring \
        php82-mysqli \
        curl \
		mariadb-client \
        wget \
        netcat-openbsd && \
    sed -i 's/^;daemonize = yes/daemonize = no/' /etc/php82/php-fpm.conf && \
    sed -i 's|^listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|' /etc/php82/php-fpm.d/www.conf && \
    adduser -D -u 83 -G www-data www-data && \
    curl -sSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
      -o /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp && \
    ln -sf /usr/bin/php82 /usr/bin/php

WORKDIR /var/www/html

RUN mkdir -p /run/php && \
    chown -R nobody:nogroup /var/www/html

COPY www.conf /etc/php82/php-fpm.d/
COPY create_wp.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wp.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/create_wp.sh"]
CMD ["php-fpm82", "-F"]
