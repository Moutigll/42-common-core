#!/bin/sh
set -e

if [ -z "$SSH_KEY" ]; then
	echo "[!] SSH_KEY not set!"
	exit 1
fi

echo "[i] Setting up SSH key..."
mkdir -p /root/.ssh
echo "$SSH_KEY" > /root/.ssh/id_ed25519
chmod 600 /root/.ssh/id_ed25519

echo "[i] Checking if local databases exist..."
if ! ls /app/OSTJourney/instance/*.db >/dev/null 2>&1; then
	echo "[i] No local databases found. Copying from remote..."
	scp -i /root/.ssh/id_ed25519 -o StrictHostKeyChecking=no \
		ubuntu@176.181.239.55:/home/server/instance/*.db \
		/app/OSTJourney/instance/
else
	echo "[i] Local databases already exist. Skipping copy."
fi

echo "[i] Synchronizing cover images..."
rsync -avz -e "ssh -i /root/.ssh/id_ed25519 -o StrictHostKeyChecking=no" \
	ubuntu@176.181.239.55:/home/server/static/images/covers/ \
	/app/OSTJourney/static/images/covers/

echo "[i] Starting app..."
exec python3 app.py
