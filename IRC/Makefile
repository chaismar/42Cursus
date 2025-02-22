NAME	=IRC
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g
RM		= rm -rf

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean re

SRCS	= 	Messages/nick.cpp\
			Messages/user.cpp\
			Messages/pass.cpp\
			Messages/quit.cpp\
			Messages/motd.cpp\
			Messages/ping.cpp\
			Messages/whois.cpp\
			main.cpp\
			Server.cpp\
			Client.cpp\
			Channel.cpp\
			Messages/join.cpp\
			Messages/part.cpp\
			Messages/privmsg.cpp\
			Messages/topic.cpp\
			Messages/invite.cpp\
			Messages/kick.cpp\
			Messages/mode.cpp\


HEADER = header.hpp\
		Server.hpp\
		Client.hpp\
		Message.cpp\
		Channel.cpp

all: $(NAME)

$(NAME): ${SRCS} ${HEADER}
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) ${SRCS} -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

clean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

fclean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: clean all