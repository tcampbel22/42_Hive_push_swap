#---------------------------------Archive-------------------------------------#
NAME = push_swap
LIBFTNAME = libft.a

#---------------------------------Flags---------------------------------------#
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f

#---------------------------------Directories---------------------------------#
SRC_DIR = .
LIBFT_DIR = ./libft

#---------------------------------Source Files--------------------------------#
SRC_FLS = 	$(SRC_DIR)/push_swap.c $(SRC_DIR)/build_list.c $(SRC_DIR)/push.c\
			$(SRC_DIR)/swap.c $(SRC_DIR)/rotate.c $(SRC_DIR)/reverse_rotate.c\
			$(SRC_DIR)/error_handling.c $(SRC_DIR)/stack_utils.c $(SRC_DIR)/small_sort.c\
			$(SRC_DIR)/algo_utils.c $(SRC_DIR)/big_sort.c $(SRC_DIR)/shift_stacks.c\
			$(SRC_DIR)/algo_utils_a.c

#---------------------------------Colours-------------------------------------#
GREEN= \033[1;32m
CYAN= \033[1;36m
PURPLE= \033[1;35m
END= \033[0m

#---------------------------------Rules---------------------------------------#
all: $(NAME)

OBJS = $(SRC_FLS:.c=.o)

$(NAME): $(OBJS)
	@echo "${PURPLE}Compiling Libft${END}"
	@echo "${PURPLE}Compiling Push_Swap${END}"
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) -o $@ 
	@echo "${GREEN}Push_Swap Compiled Successfully${END}"
clean:
	$(RM) $(OBJS)
	@make clean -C libft/
	@echo "${GREEN}Push_Swap Cleaned${END}"

fclean: clean
	$(RM) $(NAME)
	@rm -f libft/${LIBFTNAME}

re: fclean all

.PHONY: all clean fclean re
