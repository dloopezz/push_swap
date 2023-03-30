NAME = push_swap
#NAME_BONUS = push_swap_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
LIBFT = ./libft/libft.a
LIB = src/push_swap.h
#LIB_BONUS = src/push_swap_bonus.h
SRC_PATH = ./src/
#SRC_PATH_BONUS = ./src_bonus/

SRC =	push_swap.c\
		utils.c\

#SRC_BONUS =	main_bonus.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))
#SRCS_BONUS = $(addprefix $(SRC_PATH_BONUS), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft $(NAME)

#bonus: make_libft $(NAME_BONUS)

make_libft:
	@make all -C ./libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -I $(LIB) $(LIBFT) -o $(NAME)

#$(NAME_BONUS): $(OBJS_BONUS)
#	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIB_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@rm -rf $(OBJS_PATH)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus