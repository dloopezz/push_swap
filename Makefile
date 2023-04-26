NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
LIBFT = ./libft/libft.a
LIB = src/push_swap.h
SRC_PATH = ./src/

SRC =	push_swap.c\
		parsing.c\
		utils.c\
		moves.c\
		list_utils.c\
		list_utils2.c\
		list_utils3.c\
		write_moves.c\
		algorytms.c\
		radix.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "compiling libft..."
	@make all -sC ./libft
	@echo "compiling push_swap..."
	@$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) -o $(NAME)
	@echo "push_swap compiled!!"

clean:
	@echo "cleaning everything..."
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -sC ./libft
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -sC ./libft
	@rm -rf $(OBJS_PATH)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus