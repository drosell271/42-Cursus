# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 11:06:47 by drosell-          #+#    #+#              #
#    Updated: 2022/12/01 13:32:42 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
#                                              FILES                          #
###############################################################################
CFILES		= \
			Sources/main.c Sources/check_map.c Sources/mapping.c Sources/print_map.c \
			Sources/utils_1.c \

OBJS	=	${CFILES:.c=.o}

CLIBFT		= \
			Extra/ft_atoi.c Extra/ft_bzero.c Extra/ft_calloc.c \
			Extra/ft_isalnum.c Extra/ft_isalpha.c Extra/ft_isascii.c \
			Extra/ft_isdigit.c Extra/ft_isprint.c Extra/ft_memchr.c \
			Extra/ft_memcmp.c Extra/ft_memcpy.c Extra/ft_memmove.c \
			Extra/ft_memset.c Extra/ft_strchr.c Extra/ft_strdup.c \
			Extra/ft_strlcat.c Extra/ft_strlcpy.c Extra/ft_strlen.c \
			Extra/ft_strncmp.c Extra/ft_strnstr.c Extra/ft_strrchr.c \
			Extra/ft_tolower.c Extra/ft_toupper.c Extra/ft_substr.c \
			Extra/ft_strjoin.c Extra/ft_strtrim.c Extra/ft_putchar_fd.c \
			Extra/ft_putstr_fd.c Extra/ft_putendl_fd.c Extra/ft_putnbr_fd.c \
			Extra/ft_itoa.c Extra/ft_strmapi.c Extra/ft_striteri.c \
			Extra/ft_split.c Extra/ft_lstnew_bonus.c \
			Extra/ft_lstadd_front_bonus.c Extra/ft_lstsize_bonus.c \
			Extra/ft_lstlast_bonus.c Extra/ft_lstadd_back_bonus.c \
			Extra/ft_lstdelone_bonus.c Extra/ft_lstclear_bonus.c \
			Extra/ft_lstiter_bonus.c Extra/ft_lstmap_bonus.c \
			Extra/ft_printf.c Extra/get_next_line.c Extra/get_next_line_bonus.c \
			Extra/ft_printf_utils_1.c Extra/ft_printf_utils_2.c\

OLIBFT	=	${CLIBFT:.c=.o}

###############################################################################
#                                              SETTINGS                       #
###############################################################################
NAME = so_long
HDRS = so_long.h

NLIBRARY= libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OPGRAFIC = -lmlx -framework OpenGL -framework AppKit

AR = ar
ARFLAGS = -rcs
RM = rm -f

LIBFT = $(OLIBFT)

###############################################################################
#                                              OPTIONS                        #
###############################################################################
all: ${NAME}

${NAME}: ${NLIBRARY} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${NLIBRARY} ${OPGRAFIC} -o $@ #-fsanitize=address -g
	@echo "Created so_long."

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created LIBFT."

.c.o:
		 @${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OBJS} ${LIBFT}
		@echo "Delete .o."

fclean: clean
		@${RM} ${NLIBRARY} ${NAME}
		@echo "Delete libft.a and so_long."

re: fclean all

help:
	@echo "Options of MakeFile:"
	@echo "\tDeault: Created '${NAME}'"
	@echo "\tclean: Delete '.o'."
	@echo "\tfclean: Delete'.o', '${NLIBRARY}' and '${NAME}'"
	@echo "\tre: Delete '.o', '${NLIBRARY}', '${NAME}' and creates '${NAME}'"
	@echo "MakeFile by tvillare."

.PHONY = all clean fclean re help