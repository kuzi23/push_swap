# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:25:12 by mkwizera          #+#    #+#              #
#    Updated: 2025/01/14 20:05:20 by marvin           ###   ########.fr        #
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
       inititation_utils.c \
       intial_condition_utils.c \
       main.c \
       node_a.c \
       node_b.c \
       push_swap.c \
       push.c \
       reverse_rotation.c \
       rotate.c \
       sorted_three.c \
       stack_init.c \
       stack_sorting.c \
       swapping.c \


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


