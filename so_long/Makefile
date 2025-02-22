NAME	:= so_long

SRCS_FILES_BONUS    := check_DFS.c\
				BFS.c\
				BFS2.c\
				enemie.c\
				handle_click.c\
				collectible.c\
				debouncing.c\
				DFS.c\
				end_game.c\
				end_game2.c\
				init_frames.c\
				init.c\
				main.c\
				key_management.c\
				manage_error1.c\
				manage_error2.c\
				manage_error3.c\
				manage_map1.c\
				manage_map2.c\
				movements.c\
				print.c\
				print2.c

SRCS_FILES := check_DFS.c\
			handle_click.c\
			collectible.c\
			DFS.c\
			end_game.c\
			end_game2.c\
			key_management.c\
			manage_error1.c\
			manage_error2.c\
			manage_error3.c\
			manage_map1.c\
			manage_map2.c\
			print.c\
			main.c\
			init.c\
			putnbr.c
			
HEADER_FILE    := so_long.h

SRCS_DIR    := ./src/
INC_DIR	:= ./includes/
SRCS_DIR_BONUS := ./src/bonus/

MLX	    := ./includes/minilibx-linux/libmlx.a
MLX_INC	:= ./includes/minilibx-linux
MLX_LIB	:= -lX11 -lXext -L ./includes/minilibx-linux -lmlx

SRCS	:= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS	:= ${SRCS:.c=.o}
HEADER	:= $(addprefix ${INC_DIR}, ${HEADER_FILE})
SRCS_BONUS := $(addprefix ${SRCS_DIR_BONUS}, ${SRCS_FILES_BONUS}) 
OBJS_BONUS := ${SRCS_BONUS:.c=.o}
HEADER_FILE_BONUS	:= $(addprefix ${SRCS_BONUS}, ${HEADER_FILE})

CC	    := cc
CC_FLAGS    := -Wall -Wextra -Werror

RM	    := rm -f

%.o : %.c    ${HEADER}
	    ${CC} ${CC_FLAGS} -g -I${INC_DIR} -I${MLX_INC} -c $< -o $@

all:	${NAME}

${NAME}:    ${OBJS} ${MLX}
	    ${CC} ${CC_FLAGS} -g -I${INC_DIR} -I${MLX_INC} -o ${NAME} ${OBJS} ${MLX_LIB}

${MLX}:
	    make -C ${MLX_INC}

bonus:  	${OBJS_BONUS} ${MLX}
	    ${CC} ${CC_FLAGS} -g -I${INC_DIR} -I${MLX_INC} -o ${NAME} ${OBJS_BONUS} ${MLX_LIB}

clean:
	    make -C ${MLX_INC} clean
	    ${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	    ${RM} ${NAME}

re:	    fclean all

.PHONY:     all clean fclean re