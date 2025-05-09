#!/bin/sh

# Variables d'environnement nécessaires
: "${KUMA_DB:=kuma.db}"
: "${ADMIN_USERNAME:=admin}"
: "${ADMIN_PASSWORD:=adminpass}"
: "${MONITOR_NAME:=Homepage}"
: "${MONITOR_URL:=https://example.com}"
: "${MONITOR_INTERVAL:=60}"

# Vérification des dépendances
if ! command -v sqlite3 >/dev/null 2>&1; then
	echo "sqlite3 not found"
	exit 1
fi

if ! command -v node >/dev/null 2>&1; then
	echo "node not found (needed for bcrypt hash)"
	exit 1
fi

# Générer le hash du mot de passe admin
ADMIN_HASH=$(node -e "console.log(require('bcrypt').hashSync(process.env.ADMIN_PASSWORD, 10))")
if [ -z "$ADMIN_HASH" ]; then
	echo "Failed to hash password"
	exit 1
fi

# Supprimer l'ancienne DB si elle existe
rm -f "$KUMA_DB"

# Créer les tables en important le schéma initial depuis un container Uptime Kuma ou à partir d’un export
# Ici, on va juste créer un minimum pour que ça fonctionne.

sqlite3 "$KUMA_DB" <<EOF
PRAGMA foreign_keys=OFF;

-- Création des tables minimales requises
CREATE TABLE user (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	username TEXT NOT NULL,
	password TEXT NOT NULL,
	role TEXT NOT NULL,
	active INTEGER NOT NULL DEFAULT 1,
	created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE monitor (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT NOT NULL,
	type TEXT NOT NULL,
	url TEXT,
	interval INTEGER NOT NULL,
	active INTEGER NOT NULL DEFAULT 1,
	created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
	hostname TEXT
);

-- Insertion de l'utilisateur admin
INSERT INTO user (username, password, role, active)
VALUES ('$ADMIN_USERNAME', '$ADMIN_HASH', 'admin', 1);

-- Insertion d’un moniteur
INSERT INTO monitor (name, type, url, interval, active, hostname)
VALUES ('$MONITOR_NAME', 'http', '$MONITOR_URL', $MONITOR_INTERVAL, 1, '');
EOF

echo "✅ Kuma DB initialized at $KUMA_DB"
