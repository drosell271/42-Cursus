# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:29:08 by drosell-          #+#    #+#              #
#    Updated: 2022/10/08 16:04:56 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_printf_utils_1.c \
		ft_printf_utils_2.c
OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
COLOUR_RED=\033[0;31m
COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m
OBL_MSG = COMPILADA LA PARTE OBLIGATORIA
CLN_MSG = CLEAN FINALIZADO
FCLN_MSG = FCLEAN FINALIZADO

all: $(NAME)

clean:
	@$(RM) $(RMFLAGS) -f $(OBJS)
	@echo "$(COLOUR_RED)$(CLN_MSG)$(COLOUR_END)"

fclean:
	@$(RM) $(RMFLAGS) -f $(OBJS)
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(COLOUR_RED)$(FCLN_MSG)$(COLOUR_END)"

re: fclean all

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(COLOUR_GREEN)$(OBL_MSG)$(COLOUR_END)"

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re