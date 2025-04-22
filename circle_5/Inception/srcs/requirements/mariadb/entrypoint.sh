#!/bin/sh
set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "[i] Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
    echo "[i] MariaDB data directory initialized."
fi

echo "[i] Starting temporary MariaDB..."
/usr/bin/mariadbd --datadir=/var/lib/mysql --user=mysql &
PID_DB=$!

echo "[i] Waiting for MariaDB to accept connections..."
until mysqladmin ping --silent; do
    sleep 1
done

echo "[i] MariaDB is ready for setup."

INIT_FLAG="/var/lib/mysql/.initialized"
if [ ! -f "$INIT_FLAG" ]; then
    echo "[i] First-run setup: creating database and user..."
    SQL="CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;"
    SQL="$SQL CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    SQL="$SQL GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';"
    SQL="$SQL FLUSH PRIVILEGES;"
    mysql -u root -e "$SQL"

    touch "$INIT_FLAG"
    echo "[i] First-run setup complete. Shutting down temporary server..."
    mysqladmin -u root shutdown
    wait $PID_DB
fi

exec /usr/bin/mariadbd --defaults-file=/etc/my.cnf --user=mysql --datadir=/var/lib/mysql

