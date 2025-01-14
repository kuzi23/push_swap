# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:25:12 by mkwizera          #+#    #+#              #
#    Updated: 2025/01/14 15:15:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# resources
INC = -Iinc
INCLUDELIBFT = -Ilibft
OBJ = $(SRCS:%.c=%.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Source files
SRCS = handlers.c \
       nodes_a.c \
       nodes_b.c \
       intial_condition_utils.c \
       main.c \
       push_swap.c \
       push.c \
       reverse_rotation.c \
       rotate.c \
       stack_sorting.c \
       stack_init_utilis.c \
       stack_init.c \
       swap.c \
       sorted_three.c



# Compiler and flags

# Default target
all: $(NAME)

%.o: %.c
	@echo "Compiling $< with includes: $(INC) $(INCLUDELIBFT)"
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) -c $< -o $@

$(NAME): $(OBJ) libft
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) -o $(NAME) $(OBJ) -Llibft -lft

libft:
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re libft


