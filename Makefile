# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 19:15:58 by wdaher-a          #+#    #+#              #
#    Updated: 2018/12/15 20:08:28 by hde-ghel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= ./main.c\
     ./check_if_valid.c ./valid.c ./error.c ./map.c ./solve.c ./utils.c ./read.c

OBJ=$(SRC:.c=.o)

RM=rm -f

LIBFT= ./libft/libft.a 

$(NAME):
		make -C ./libft/
		$(CC) $(CFLAGS) -c $(SRC)
		$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

all:$(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft/

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
