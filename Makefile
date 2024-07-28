
#compiler and flags
CC = gcc
CFLAGS  =-Wall -Wextra -Werror
RM = rm -f

#sources
SRCS =	init_stack_a/ft_strol.c \
		init_stack_a/init_stack_a.c \
		role/push_to_dest.c \
		role/reverseRotate.c \
		role/rotate.c \
		role/swap.c \
		pushswap/init_a.c \
		pushswap/init_b.c \
		pushswap/move_a_to_b.c \
		sort_stacks/push_swap.c \
		sort_stacks/sort_stacks.c \
		sort_three/sort_three.c \
		stack_sorted/stack_sorted.c \
		stack_sorted/stack_len.c\
		libft/ft_split2.c \
		libft/ft_strlen.c \
		main.c \

#object files
OBJ = $(SRCS:%.c=%.o)

#Executable name
NAME = push_swap

#default target
all: $(NAME)

#Rule for building object files
%.o:%.c
		@echo "compiling all"
		$(CC) $(CFLAGS) -c $< -o $@

#Rule for building the executable
$(NAME): $(OBJ) libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

#clean object files
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
