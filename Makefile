#---------------------------------Archive-------------------------------------#
NAME = push_swap.a
LIBFTNAME = libft.a

#---------------------------------Flags---------------------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#---------------------------------Directories---------------------------------#
SRC_DIR = .
LIBFT_DIR = ./libft

#---------------------------------Source Files--------------------------------#
SRC_FLS = $(SRC_DIR)/push_swap.c

#---------------------------------Rules---------------------------------------#
all: $(NAME)

OBJS = $(SRC_FLS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) -o $@ 

clean:
	$(RM) $(OBJS) 
	@make clean -C libft/

fclean:
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
