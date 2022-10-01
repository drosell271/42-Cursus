CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFILES = 	ft_atoi.c \
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
			ft_strtrim.c	

BFILES =	ft_lstnew.c		\
			ft_lstadd_front.c \
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c \
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c
			
MOBJS = ${MFILES:.c=.o}
BOBJS = ${BFILES:.c=.o}
NAME = libft.a
RM = rm -rf
LBUILDER = ar
LFLAGS = -crs

.PHONY: all re fclean clean bclean bonus 

all:	fclean ${NAME} bonus

${NAME}:
	@${CC} ${CFLAGS} -c ${MFILES}
	${LBUILDER} ${LFLAGS} ${NAME} ${MOBJS}

bonus:
	@${CC} -c ${CFLAGS} ${MFILES} ${BFILES}
	${LBUILDER} ${LFLAGS} ${NAME} ${MOBJS} ${BOBJS}

re:		fclean all

fclean:		clean	bclean
		@$(RM) ${NAME}

clean:
	@$(RM) $(MOBJS)

bclean:
	@$(RM) $(BOBJS)
