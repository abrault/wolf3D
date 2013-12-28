#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviala <aviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 18:12:48 by aviala            #+#    #+#              #
#    Updated: 2013/12/27 23:18:37 by aviala           ###   ########.fr        #
#                                                                              #
#******************************************************************************#


CC = clang
LD = $(CC)
CFLAGS = -Wall -c -std=c89
LDFLAGS = `SDL2/bin/sdl2-config --cflags --libs`
NAME = SDL

all: SDL2 $(NAME)

$(NAME): main.o
	$(CC) $(LDFLAGS) -L./libft/ -lft $< -o $@

main.o: main.c
	$(CC) $(LDFLAGS) $(CFLAGS) -L./libft/ -lft $< -o $@

clean:
	rm *.o && rm $(NAME)

fclean:
	rm -f $(NAME)

re: clean fclean all

# Do all the SDL2 building junk.

SDL2:
	mkdir -p SDL2/junk
	tar xf SDL2-2.0.1.tar.gz
	( cd SDL2-2.0.1 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.1.tar.gz SDL2-2.0.1 SDL2/junk
