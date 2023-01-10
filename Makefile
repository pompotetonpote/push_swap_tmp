CC			= gcc -g
CFLAGS		= -Werror -Wall -Wextra -fsanitize=address
NAME		= push_swap

SRC_PATH 	= src/
OBJ_PATH 	= obj/

SRC			= main.c \
			  fill_stack.c \
			  check_inputs.c \
			  utils_checks.c \
			  utils.c \
			  utils2.c \
			  utils3.c \
			  stack.c \
			  index.c \
			  sort.c \
			  sort_three.c \
			  rotate.c \
			  reverse_rotate.c \
			  push.c \
			  swap.c \
			  position.c \
			  operations.c \
			  costs.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 