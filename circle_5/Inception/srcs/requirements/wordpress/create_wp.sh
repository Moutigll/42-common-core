#!/bin/sh
set -e

if [ -f wp-config.php ]; then
	echo "[i] WordPress already installed"
else
	echo "[i] Downloading WordPress 6.7.2..."
	wget -q https://wordpress.org/wordpress-6.7.2.tar.gz -O wordpress.tar.gz

	echo "[i] Extracting WordPress..."
	tar xzf wordpress.tar.gz --strip-components=1
	rm wordpress.tar.gz

	echo "[i] Generating minimal wp-config.php..."

	cat > wp-config.php <<EOF
‎ 
<?php

define( 'DB_NAME', '${MYSQL_DATABASE}' );
define( 'DB_USER', '${MYSQL_USER}' );
define( 'DB_PASSWORD', '${MYSQL_PASSWORD}' );
define( 'DB_HOST', '${MYSQL_HOSTNAME}' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

\$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
EOF

fi

exec "$@"
