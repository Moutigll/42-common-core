ENV_FILE := srcs/.env
ifeq (,$(wildcard $(ENV_FILE)))
  $(error "$(ENV_FILE) is missing, please create it with LOGIN=<your-login>")
endif

include $(ENV_FILE)
export LOGIN

DATA_DIR  := $(HOME)/data
MYSQL_DIR := $(DATA_DIR)/mysql
WP_DIR    := $(DATA_DIR)/wordpress

SUDO := sudo -E
COMPOSE := $(SUDO) docker-compose -f ./srcs/docker-compose.yaml

.PHONY: all build up log down stop start clean fclean status

all: up

build:
	@echo "[+] Creating host dirs for volumes…"
	@mkdir -p $(MYSQL_DIR) $(WP_DIR)
	@sudo chmod 775 $(DATA_DIR)
	@echo "[+] Building Docker images…"
	@$(COMPOSE) build

up: build
	@echo "[+] Starting containers in detached mode…"
	@$(COMPOSE) up -d

log: build
	@echo "[+] Starting containers with logs attached…"
	@$(COMPOSE) up

down:
	@echo "[+] Stopping & removing containers…"
	@$(COMPOSE) down

stop:
	@echo "[+] Stopping containers…"
	@$(COMPOSE) stop

start:
	@echo "[+] Starting containers…"
	@$(COMPOSE) start

clean:
	@echo "[+] Pruning Docker (containers, volumes, images)…"
	@$(COMPOSE) down -v --rmi all
	@sudo docker system prune -af

fclean:
	@echo "[+] Full clean (Docker + host data)…"
	@sudo docker system prune -af
	@sudo docker volume prune -f
	@sudo docker network prune -f
	@sudo rm -rf $(DATA_DIR)/*

status:
	@echo "[+] Docker containers status:"
	@sudo docker ps
