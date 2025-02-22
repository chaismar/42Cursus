NAME = libftprintf.a

HEADER = src/ft_printf.h

LIBFT = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_strnstr.c\
    ft_atoi.c\
    ft_strdup.c\
	ft_split.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putstr_fd.c\
	ft_strjoin.c\
	ft_substr.c\
	ft_strncmp.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_strlcpy.c\
	ft_putnbr_fd.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
    ft_memmove.c\
    ft_memchr.c\
	ft_memcmp.c\
	ft_strtrim.c\
	ft_calloc.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

SRC = ft_printf.c\
	ft_itoa_hex.c\
	ft_itoa_u.c\
	str_management.c\
	converter1.c\
	converter2.c\

LIBFTS = $(addprefix ./libft/,${LIBFT})

SRCS = $(addprefix ./src/,${SRC})

OBJS = ${SRCS:.c=.o} ${LIBFTS:.c=.o}

AR = ar -rc
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	${AR} $@ ${OBJS}

.o: .c
	${CC} -c ${CFLAGS} $< -o $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: clean fclean re all