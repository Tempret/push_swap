#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 15:20:54 by dkhlopov          #+#    #+#              #
#    Updated: 2017/04/21 18:28:47 by dkhlopov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = push_swap

NAME2 = checker

NAME3 = random

LIB = libft.a

FLAGS = -Wall -Wextra -Werror 

SRC = push_swap.c stack_manipulations.c  stack_manipulations.c \
	checker.c randomizer.c get_pivot.c simple_case_sort.c recursion_fc.c \
	three_elem_sort_b.c three_elem_sort_a.c validation.c optimization.c addition.c \
	visualisation.c init.c vis_init.c vis_addition.c vis_put_line.c vis_delim_line.c \
	make_instructions.c vis_events.c

OBJ = $(SRC:.c=.o)

OBJ1 = push_swap.o stack_manipulations.o get_pivot.o simple_case_sort.o \
	recursion_fc.o three_elem_sort_b.o three_elem_sort_a.o optimization.o validation.o \
	addition.o init.o
 
OBJ2 = checker.o stack_manipulations.o validation.o addition.o visualisation.o vis_init.o \
	   vis_addition.o vis_put_line.o vis_delim_line.o make_instructions.o vis_events.o

OBJ3 = randomizer.o

all : $(LIB) $(NAME1) $(NAME2) $(NAME3)

$(LIB) : 
	make -C ./libft

%.o : ./src/%.c
	gcc $(FLAGS) -c -o $@ $< -I./includes

$(NAME1) : $(OBJ) 
	gcc $(FLAGS) -o $(NAME1) $(OBJ1) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

$(NAME2) : $(OBJ)
	gcc $(FLAGS) -o $(NAME2) $(OBJ2) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

$(NAME3) : $(OBJ)
	gcc $(FLAGS) -o $(NAME3) $(OBJ3) -L libft/ -lft

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME1) $(NAME2) $(NAME3)

re : fclean all

libclean : 
	make clean -C ./libft

libfclean : libclean
	make fclean -C ./libft
