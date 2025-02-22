NAME 		:= pipex

NAME_BONUS	:= pipex_bonus

BONUS_FILES	:= childs.c\
				close.c\
				heredoc.c\
				pipex_bonus.c\
				usefull.c\
				usefull2.c

SRCS		:= child.c\
				close.c\
				pipex.c\
				usefull.c\

HEADER := pipex.h
HEADER_BONUS := bonus/pipex_bonus.h

LIBFT := ./libft/libft.a
LIBFT_LIB := ./libft

CC := cc
CC_FLAGS := -Wall -Wextra -Werror
RM := rm -f
BONUS_DIR := bonus/

BONUS := $(addprefix ${BONUS_DIR}, ${BONUS_FILES})
OBJS := ${SRCS:.c=.o}
OBJS_BONUS := ${BONUS:.c=.o}

%.o : %.c	${HEADER}
	    ${CC} ${CC_FLAGS} -g -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
	 ${CC} ${CC_FLAGS} -o ${NAME} ${OBJS} ${LIBFT}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT}
	${CC} ${CC_FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT}

${LIBFT}:
		make -C ${LIBFT_LIB}

bonus:	${NAME_BONUS}

all:	${NAME}

clean:
	    ${RM} ${OBJS} ${OBJS_BONUS}
		make clean -C ${LIBFT_LIB}

seed :
	${RM} *.seed ${RM} */*.seed

fclean:	clean 
		make seed
	    ${RM} ${NAME} ${NAME_BONUS} ${LIBFT} 

re:	    fclean 
		make all

.PHONY: all clean fclean re bonus