# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 13:50:21 by abrault           #+#    #+#              #
#    Updated: 2014/01/03 16:09:47 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3D

SRC = main.c

LIB = libft/libft.a

LIB_INC = libft/includes/ -I/usr/X11R6/include

LIB_DIR = libft

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -L/usr/X11/lib -lXext -lX11 -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(MFLAGS) $(LIB)

$(LIB):
	cd $(LIB_DIR) && $(MAKE)

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@ -I . -I $(LIB_INC)

clean:
	cd $(LIB_DIR) && $(MAKE) clean
	rm -rf $(OBJ)


fclean:	clean
	cd $(LIB_DIR) && $(MAKE) fclean
	rm -rf $(NAME)


re: fclean all