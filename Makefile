DC := sudo docker-compose -f srcs/docker-compose.yml

all: up

re: fclean up

up:
	$(DC) up -d

down:
	$(DC) down

fclean: down
	@sudo docker image rm $$(sudo docker image ls -aq)  2>/dev/null || echo No image to delete
	@sudo docker volume rm $$(sudo docker volume ls -q) 2>/dev/null || echo No volume to delete
	sudo docker system prune -af --volumes
	sudo rm -rf /home/njegat/data/maria/*
	sudo rm -rf /home/njegat/data/wp/*

.PHONY: all re clean fclean up down

