#!/bin/sh
set -e

INIT_FLAG="/var/lib/mysql/.initialized"

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "[i] Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
    echo "[i] Data directory initialized."
fi

if [ ! -f "$INIT_FLAG" ]; then
    echo "[i] Starting temporary MariaDB for first-run setup..."
    /usr/bin/mariadbd --datadir=/var/lib/mysql --user=mysql --skip-networking &
    PID_TMP=$!

    echo "[i] Waiting for temporary MariaDB to accept connections..."
    until mysqladmin ping --silent; do
        sleep 1
    done

    echo "[i] Running first-run SQL setup..."
    SQL="CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;"
    SQL="$SQL CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    SQL="$SQL CREATE USER IF NOT EXISTS '$MYSQL_USER2'@'%' IDENTIFIED BY '$MYSQL_PASSWORD2';"
    SQL="$SQL GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';"
    SQL="$SQL GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER2'@'%';"
    SQL="$SQL FLUSH PRIVILEGES;"
    mysql -u root -e "$SQL"

    touch "$INIT_FLAG"
    echo "[i] First-run setup complete, shutting down temporary server..."
    mysqladmin -u root shutdown
    wait $PID_TMP
fi

echo "[i] Launching MariaDB..."
exec /usr/bin/mariadbd --defaults-file=/etc/my.cnf --datadir=/var/lib/mysql --user=mysql
