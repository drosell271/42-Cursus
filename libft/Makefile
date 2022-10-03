# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:29:08 by drosell-          #+#    #+#              #
#    Updated: 2022/10/02 18:38:53 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
    	ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
        ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
        ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c\
    	ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
        ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
        ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c
SRCS_B =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
            ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
            ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
COLOUR_RED=\033[0;31m
COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m
OBL_MSG = COMPILADA LA PARTE OBLIGATORIA
BONUS_MSG = COMPILADAS LAS DOS PARTES
CLN_MSG = CLEAN FINALIZADO
FCLN_MSG = FCLEAN FINALIZADO

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B) 
	MSG = $(BONUS_MSG)
else
	TOTAL_OBJS = $(OBJS)
	MSG = $(OBL_MSG)
endif


all: $(NAME)

clean:
	@$(RM) $(RMFLAGS) -f $(OBJS) $(OBJS_B)
	@echo "$(COLOUR_RED)$(CLN_MSG)$(COLOUR_END)"

fclean:
	@$(RM) $(RMFLAGS) -f $(OBJS) $(OBJS_B)
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(COLOUR_RED)$(FCLN_MSG)$(COLOUR_END)"

re: fclean all

bonus:
	@make --no-print-directory WITH_BONUS=1

$(NAME): $(TOTAL_OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(COLOUR_GREEN)$(MSG)$(COLOUR_END)"

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus