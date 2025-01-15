CC = cc
SRC = cost_target.c errors_handler.c free_matrix.c from_a_to_b.c init_stacks.c instructions1.c move_to_top.c parse_check_args.c \
	push_swap.c shared_instructions.c sort_stack.c stack.c utils.c
CFLAGS = -Wall -Wextra -Werror

GREEN= \033[0;32m
NC= \033[0m 


LIBS = libft/libft.a

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: libft $(NAME)
	@echo "✅ $(GREEN)Build complete.$(NC)"
	@echo "$(GREEN)▶️ Run ./$(NAME) <ARGS>$(NC)"

$(NAME): $(OBJS)
	@echo "🔗 Linking object files into $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c push_swap.h
	@echo "🛠 Compiling $< ..."
	@$(CC) $(CFLAGS)  -c $< -o $@

libft:
	@make -C libft

clean:
	@echo "🗑️ Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "🗑️ Cleaning all generated files..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
