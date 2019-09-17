# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 12:17:02 by jflorent          #+#    #+#              #
#    Updated: 2019/09/17 12:36:11 by jflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $^ 

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
