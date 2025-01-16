CC = cc

SRC = mondatory/cost_target.c mondatory/errors_handler.c mondatory/free_matrix.c mondatory/from_a_to_b.c\
	mondatory/init_stacks.c mondatory/instructions1.c mondatory/instructions2.c \
	mondatory/instructions3.c mondatory/move_to_top.c mondatory/parse_check_args.c mondatory/push_swap.c \
	mondatory/shared_instructions.c mondatory/sort_stack.c mondatory/stack.c mondatory/utils.c mondatory/utils2.c

B_SRC = bonus/check_valid_args_bonus.c bonus/checker_bonus.c bonus/errors_handler_bonus.c \
	bonus/free_matrix_bonus.c bonus/init_stacks_bonus.c bonus/instructions1_bonus.c bonus/instructions2_bonus.c \
	 bonus/instructions3_bonus.c bonus/stack_bonus_bonus.c bonus/utils2_bonus_bonus.c bonus/utils_bonus.c

CFLAGS = -Wall -Wextra -Werror

GREEN= \033[0;32m
NC= \033[0m 

LIBS = libft/libft.a

OBJS = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

NAME = push_swap
B_NAME = checker


all: libft $(NAME)
	@echo "✅ $(GREEN)Build complete.$(NC)"
	@echo "$(GREEN)▶️ Run ./$(NAME) <ARGS>$(NC)"

bonus : libft $(B_NAME) $(B_OBJS)
	@echo "✅ $(GREEN)Build complete.$(NC)"
	@echo "$(GREEN)▶️ Run ./$(B_NAME) <ARGS>$(NC)"	

$(B_NAME) : $(B_OBJS)
	@echo "🔗 Linking object files into $(B_NAME)..."
	@$(CC) $(B_OBJS) $(LIBS) -o $(B_NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking object files into $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

bonus/%.o : bonus/%.c bonus/checker.h
	@echo "🛠 Compiling $< ..."
	@$(CC) $(CFLAGS)  -c $< -o $@	

mondatory/%.o: mondatory/%.c mondatory/push_swap.h
	@echo "🛠 Compiling $< ..."
	@$(CC) $(CFLAGS)  -c $< -o $@

libft:
	@make -C libft

clean:
	@echo "🗑️ Cleaning object files..."
	@make clean -C libft
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@echo "🗑️ Cleaning all generated files..."
	@make fclean -C libft
	@rm -rf $(NAME) $(B_NAME)

re: fclean all

.PHONY: libft  re clean fclean