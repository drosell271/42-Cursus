# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 22:26:25 by drosell-          #+#    #+#              #
#    Updated: 2023/02/28 16:27:46 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de los ejecutables
NAME1 = client
NAME2 = server

# Compilador y opciones de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorios del proyecto
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Biblioteca
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente y objetos
SRC1 = client.c
SRC2 = server.c
OBJ1 = $(addprefix $(OBJ_DIR)/, $(SRC1:.c=.o))
OBJ2 = $(addprefix $(OBJ_DIR)/, $(SRC2:.c=.o))

# Reglas
all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME1) $^

$(NAME2): $(OBJ2) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME2) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

