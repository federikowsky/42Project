all : up

up : 
	@docker compose up -d

down : 
	@docker compose down

stop : 
	@docker compose stop

start : 
	@docker compose start
build :
	@docker compose build

status : 
	@docker ps

clean :
	@docker container prune --force
	@docker image prune --force
	@docker volume prune --force
	@rm -rf ./db/data
