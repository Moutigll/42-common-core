#!/bin/sh
set -e

echo "[i] Waiting for MariaDB at ${MYSQL_HOSTNAME}..."
until mysql -h"${MYSQL_HOSTNAME}" \
           -u"${MYSQL_USER}" \
           -p"${MYSQL_PASSWORD}" \
           -e "SELECT 1" \
      > /dev/null 2>&1; do
    echo "[i] MariaDB not ready yet..."
    sleep 2
done

if [ ! -f wp-config.php ]; then
    echo "[i] Downloading WordPress..."
    wget -q https://wordpress.org/wordpress-6.7.2.tar.gz -O wordpress.tar.gz

    echo "[i] Extracting WordPress..."
    tar xzf wordpress.tar.gz --strip-components=1
    rm wordpress.tar.gz

    echo "[i] Generating wp‑config.php..."
    cat > wp-config.php <<EOF
<?php
define('DB_NAME',     '${MYSQL_DATABASE}');
define('DB_USER',     '${MYSQL_USER}');
define('DB_PASSWORD', '${MYSQL_PASSWORD}');
define('DB_HOST',     '${MYSQL_HOSTNAME}');
define('DB_CHARSET',  'utf8');
define('DB_COLLATE',  '');
define('WP_REDIS_HOST','redis');
define('WP_REDIS_PORT',6379);
\$table_prefix = 'wp_';
define('WP_DEBUG', false);
if (!defined('ABSPATH')) define('ABSPATH', __DIR__ . '/');
require_once ABSPATH . 'wp-settings.php';
EOF
fi

if ! wp core is-installed --allow-root; then
    echo "[i] Installing WordPress core..."
    wp core install \
      --url="https://${DOMAIN_NAME}" \
      --title="${WORDPRESS_TITLE}" \
      --admin_user="${WORDPRESS_ADMIN_USER}" \
      --admin_password="${WORDPRESS_ADMIN_PASSWORD}" \
      --admin_email="${WORDPRESS_ADMIN_EMAIL}" \
      --skip-email \
      --allow-root
else
    echo "[i] WordPress already installed"
fi

echo "[i] Installing & enabling Redis Cache plugin..."
wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root || true

exec "$@"
