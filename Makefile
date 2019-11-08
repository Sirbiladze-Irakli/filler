# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/11/08 16:00:43 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLER = jormond-.filler

INC = ./inc/filler.h

LIB = libft/libft.a

# FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILES = main.c get_next_line.c tools.c solution.c parsing.c
SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

all : $(FILLER)

$(FILLER) : $(OBJ)
	@make -C libft/
	@gcc -o $(FILLER) $(OBJ) $(LIB)
	@echo "filler : $(GREEN)$(FILLER) was created$(RESET)"

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(FILLER)

re : fclean all
