all: clear
	@docker compose run debian bash

clear:
	@docker compose down --remove-orphans

re: clear all
