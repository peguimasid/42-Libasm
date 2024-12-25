NAME = libasm.a

UTIL_SRCS = $(shell find src/utils -name '*.c')

SRCS = $(shell find src -name '*.s')

OBJ	= $(SRCS:.s=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "✓ $(NAME)"

all: $(NAME)

%.o: %.s
	@nasm -f elf64 $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "✕ $(OBJ)"

fclean: clean
	@rm -f $(NAME)
	@rm -f test *.txt
	@echo "✕ $(NAME)"

re:	fclean all

test: all
	@gcc -Wall -Wextra -Werror src/main.c $(UTIL_SRCS) $(NAME) -o test && ./test && rm test

linux: linux-clean
	@docker compose -f docker/compose.yml run debian bash

linux-clean:
	@docker compose -f docker/compose.yml down --remove-orphans

.PHONY:	all clean fclean re
