NAME = libasm.a

FILES = ft_strlen.s
FILES += ft_strcpy.s
FILES += ft_strcmp.s
FILES += ft_write.s

SRCS = $(addprefix src/, $(FILES))
OBJ	 = $(SRCS:.s=.o)

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
	@gcc -Wall -Wextra -Werror src/main.c $(NAME) -o test && ./test && rm test

linux: linux-clean
	@docker compose -f docker/compose.yml run debian bash

linux-clean:
	@docker compose -f docker/compose.yml down --remove-orphans

.PHONY:	all clean fclean re
