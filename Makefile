# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshih <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 20:03:03 by sshih             #+#    #+#              #
#    Updated: 2018/06/11 20:12:25 by sshih            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = get_next_line
SRC = *.c
OBJ = *.o

all: $(NAME)
$(NAME):
	make -C libft
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) -Llibft -lft -I get_next_line.h

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(OBJ)

re: fclean all
