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


mkdir -p /app/data

cat > /app/data/db-config.json <<EOF
{
    "type": "mariadb",
    "port": 3306,
    "hostname": "${MYSQL_HOSTNAME}",
    "username": "${MYSQL_USER}",
    "password": "${MYSQL_PASSWORD}",
    "dbName": "${UPTIMEKUMA_DB}"
}
EOF

exec node server/server.js
