DOCKER_COMPOSE = sudo docker-compose -f srcs/docker-compose.yml

up:
	$(DOCKER_COMPOSE) up -d --build

down:
	$(DOCKER_COMPOSE) down

rebuild:
	$(DOCKER_COMPOSE) up -d --build --force-recreate

logs:
	$(DOCKER_COMPOSE) logs -f

clean:
	$(DOCKER_COMPOSE) down -v

fclean: clean
	sudo docker system prune -af --volumes

re: fclean up

.PHONY: up down rebuild logs clean fclean re