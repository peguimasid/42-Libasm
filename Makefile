NAME = libasm.a

SRCS = ft_strlen.s
OBJ	 = $(SRCS:.s=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) ✅"

all: $(NAME)

%.o: %.s
	@nasm -f elf64 $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(OBJ) 🗑️"

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	@echo "$(NAME) 🗑️"

re:	fclean all

test: all
	@gcc -Wall -Wextra -Werror main.c $(NAME) -o test && ./test && rm test

linux: linux-clean
	@docker compose -f docker/compose.yml run debian bash

linux-clean:
	@docker compose -f docker/compose.yml down --remove-orphans

.PHONY:	all clean fclean re
