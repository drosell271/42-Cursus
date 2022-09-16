CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 	ft_bzero.c   \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c  \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_memcpy.c  \
			ft_strlcat.c \
			ft_strlen.c  \
			ft_memset.c	 \
			ft_tolower.c 
HDRS = libft.h
OBJS = ${CFILES:.c=.o}
LIB = libft.a
RM = rm -rf

.PHONY: all re fclean clean

all:	${LIB}

${LIB}:	${OBJS}
	@ar rc ${LIB} ${OBJS}
	@ranlib ${LIB}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HDRS}

re:		fclean all

fclean:		clean
		@$(RM) ${LIB}

clean:
	@$(RM) $(OBJS)
