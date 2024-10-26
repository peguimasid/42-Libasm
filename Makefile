all: clear
	@docker compose run libasm bash

clear:
	@docker compose down --remove-orphans

re: clear all
