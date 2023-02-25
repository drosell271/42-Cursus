# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 22:26:25 by drosell-          #+#    #+#              #
#    Updated: 2023/02/22 22:26:25 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft

client: client.o libft/libft.a
	$(CC) -o $@ $^ -Llibft -lft

server.o: server.c
	$(CC) -c $(CFLAGS) $< -o $@

client.o: client.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: server.o client.o

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re

