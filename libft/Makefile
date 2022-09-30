CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 	ft_atoi.c    \
			ft_bzero.c   \
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
			ft_tolower.c \
			ft_memchr.c  \
			ft_memcmp.c	 \
			ft_strchr.c  \
			ft_strrchr.c \
			ft_calloc.c  \
			ft_strdup.c	 \
			ft_strnstr.c \
			ft_memmove.c \
			ft_substr.c  \
			ft_strjoin.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c  \
			ft_putendl_fd.c \
			ft_putnbr_fd.c  \
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_strtrim.c	\
			ft_lstnew.c		\
			ft_lstadd_front.c \
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c

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
