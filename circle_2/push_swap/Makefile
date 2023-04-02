# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 09:53:31 by drosell-          #+#    #+#              #
#    Updated: 2023/04/02 09:53:31 by drosell-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

# **************************************************************************** #

## VARIABLES ##
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
RM			=	rm -rf
DIR_HEADERS =	./Includes/
DIR_SRCS	=	./Sources/
DIR_OBJS	=	./Compiled/

# FILES #
SRC			=	push_swap.c \
				auxiliares.c \
				checkeos.c \
				moves_1.c \
				moves_2.c \
				moves_3.c \
				ordenar.c \
				ordernar_small.c \
				tamano_big.c \
				tamano_small.c \
				varios_1.c \
				varios_2.c
SRCS		=	$(SRC)

# COMPILED_SOURCES #
OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)
NAME 		=	push_swap


# **************************************************************************** #

## RULES ##

all:			$(NAME)

# VARIABLES RULES #
$(NAME):		$(OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
				@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

# COMPILED_SOURCES RULES #
$(OBJS):		| $(DIR_OBJS)
$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛ "
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@
$(DIR_OBJS):
				@mkdir $(DIR_OBJS)


# OBLIGATORY PART #

clean:
				@$(RM) $(DIR_OBJS)
				@printf "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)🗑️\n"

re:				fclean all
# PHONY #

.PHONY:			all clean fclean re norm