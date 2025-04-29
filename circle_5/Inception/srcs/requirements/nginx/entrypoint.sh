#!/bin/sh
set -e

nginx -g 'daemon off;' &

i=0
until curl -k -s https://localhost/wp-admin/install.php > /dev/null; do
	if [ "$i" -gt 10 ]; then
		echo "[!] Timeout: Nginx not responding"
		exit 1
	fi
	echo "[i] Waiting for Nginx to be ready..."
	i=$((i + 1))
	sleep 2
done

echo "[i] Sending WordPress install request..."

curl -k -c cookies.txt -b cookies.txt \
	-X POST "https://localhost/wp-admin/install.php?step=2" \
	-d "language=" \
	-d "weblog_title=${WORDPRESS_TITLE}" \
	-d "user_name=${WORDPRESS_ADMIN_USER}" \
	-d "admin_password=${WORDPRESS_ADMIN_PASSWORD}" \
	-d "admin_password2=${WORDPRESS_ADMIN_PASSWORD}" \
	-d "pw_weak=on" \
	-d "admin_email=${WORDPRESS_ADMIN_EMAIL}" \
	-d "blog_public=1" \
	-d "Submit=Install+WordPress"

killall nginx || true
sleep 1

echo "The website is available at: https://${DOMAIN_NAME}/"

exec nginx -g 'daemon off;'