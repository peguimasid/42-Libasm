NAME = libasm.a

# Source files
ASM_SRCS = $(shell find src -name '*.s')
UTIL_SRCS = $(shell find src/utils -name '*.c')

# Object files
ASM_OBJS	= $(ASM_SRCS:.s=.o)

# Default target
all: $(NAME)

# Build the library
$(NAME): $(ASM_OBJS)
	@ar rc $(NAME) $(ASM_OBJS)
	@echo "✓ $(NAME)"

# Rule to compile assembly files
%.o: %.s
	@nasm -f elf64 $< -o $@

# Clean object files
clean:
	@rm -f $(ASM_OBJS)
	@echo "✕ $(ASM_OBJS)"

# Clean all generated files
fclean: clean
	@rm -f $(NAME)
	@rm -f test *.txt
	@echo "✕ $(NAME)"

# Rebuild everything
re:	fclean all

# Run tests
test: all
	@gcc -Wall -Wextra -Werror src/main.c $(UTIL_SRCS) $(NAME) -o test && ./test && rm test

# Run in Linux environment using Docker
linux: linux-clean
	@docker compose -f docker/compose.yml run debian bash

# Clean Docker environment
linux-clean:
	@docker compose -f docker/compose.yml down --remove-orphans

.PHONY:	all clean fclean re
