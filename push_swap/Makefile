NAME := push_swap

BONUS_FILES		:= add.c\
				check_error_user.c\
				checker.c\
				check_error_user2.c\
				define_index.c\
				ft_functions.c\
				getters.c\
				push.c\
				reverse_rotate.c\
				rotate.c\
				swap.c\

GNL_FILES	:= get_next_line.c\
			get_next_line_utils.c\


SRCS	:= calc1.c\
		calc2.c\
		checkers.c\
		define_index.c\
		ft_functions.c\
		getters.c\
		push_swap.c\
		push.c\
		reverse_rotate.c\
		rotate.c\
		send_specials.c\
		senders.c\
		sort_low.c\
		sort_more.c\
		swap.c\
		use.c\

HEADER := push_swap.h
HEADER_BONUS := bonus/checker.h
HEADER_GNL := bonus/get_next_line.h

LIBFT := ./libft/libft.a
LIBFT_LIB := ./libft

CC := cc
CC_FLAGS := -Wall -Wextra -Werror
RM := rm -f
BONUS_DIR := bonus/

BONUS := $(addprefix ${BONUS_DIR}, ${BONUS_FILES})
GNL := $(addprefix ${BONUS_DIR}, ${GNL_FILES})
OBJS := ${SRCS:.c=.o}
OBJS_BONUS := ${BONUS:.c=.o}
OBJS_GNL := ${GNL:.c=.o}

%.o : %.c	${HEADER}
	    ${CC} ${CC_FLAGS} -g -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
	 ${CC} ${CC_FLAGS} -o ${NAME} ${OBJS} ${LIBFT}

${LIBFT}:
		make -C ${LIBFT_LIB}

bonus:	${OBJS_BONUS} ${OBJS_GNL} ${OBJS_GNL}
		${CC} ${CC_FLAGS} -o checker ${OBJS_BONUS} ${OBJS_GNL} ${LIBFT}

all:	${NAME}

clean:
	    ${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_GNL}
		make clean -C ${LIBFT_LIB}

fclean:	clean
	    ${RM} ${NAME} checker ${LIBFT}

re:	    fclean all

.PHONY: all clean fclean re bonus