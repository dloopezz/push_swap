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
		parsing.c\
		utils.c\
		moves.c\
		list_utils.c\
		write_moves.c\
		algorytm.c\

#SRC_BONUS =	main_bonus.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))
#SRCS_BONUS = $(addprefix $(SRC_PATH_BONUS), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

#bonus: make_libft $(NAME_BONUS)

$(NAME): $(OBJS)
	$(YELLOW) "compiling libft..." $(RESET)
	@make all -sC ./libft
	$(YELLOW) "compiling push_swap..." $(RESET)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -I $(LIB) $(LIBFT) -o $(NAME)
	$(GREEN) "push_swap compiled!!" $(RESET)

#$(NAME_BONUS): $(OBJS_BONUS)
#	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIB_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	$(BLUE) "cleaning everything..." $(RESET)
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







#===SETTINGS 	COLORS===
#===Color font code===
BLACK   = @echo "\x1B[30m"
RED     = @echo "\x1b[31m"
GREEN   = @echo "\x1b[32m"
YELLOW  = @echo "\x1b[33m"
BLUE    = @echo "\x1b[34m"
MAGENTA = @echo "\x1b[35m"
CYAN    = @echo "\x1b[36m"
WHITE   = @echo "\x1B[37m"
ORANGE  = @echo "\x1B[38;2;255;128;0m"
ROSE    = @echo "\x1B[38;2;255;151;203m"
LBLUE   = @echo "\x1B[38;2;53;149;240m"
LGREEN  = @echo "\x1B[38;2;17;245;120m"
GRAY    = @echo "\x1B[38;2;176;174;174m"
RESET 	= "\033[1;0m"

#===Color background code===
BG_BLACK   = @echo "\x1B[40m"
BG_RED     = @echo "\x1B[41m"
BG_GREEN   = @echo "\x1B[42m"
BG_YELLOW  = @echo "\x1B[43m"
BG_BLUE    = @echo "\x1B[44m"
BG_MAGENTA = @echo "\x1B[45m"
BG_CYAN    = @echo "\x1B[46m"
BG_WHITE   = @echo "\x1B[47m"
BG_ORANGE  = @echo "\x1B[48;2;255;128;0m"
BG_LBLUE   = @echo "\x1B[48;2;53;149;240m"
BG_LGREEN  = @echo "\x1B[48;2;17;245;120m"
BG_GRAY    = @echo "\x1B[48;2;176;174;174m"
BG_ROSE    = @echo "\x1B[48;2;255;151;203m"