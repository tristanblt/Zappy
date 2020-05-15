##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## Makefile
##

NAME			=	../zappy_server

SRCPATH			=	src/

SRCS_FILES		=	main.c \
					server.c \
					tools/client_tools.c \
					tools/time_tools.c \
					tools/signal_tools.c \
					tools/command_tools.c \
					tools/flux_tools.c \
					tools/map_tools.c \
					tools/server_tools.c \
					tools/args_tools.c \

SRCS			=	$(addprefix $(SRCPATH), $(SRCS_FILES))
OBJS			= 	$(SRCS:%.c=%.o)

UNAME_S	= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS	= 	-ldl -luuid
else
	LDFLAGS	= 	-ldl
endif

CFLAGS			=	-W -Wall -Wextra -Wshadow			\
					-Iinclude/ -g						\

CC				=	gcc
RM				=	rm -f

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
					$(RM) $(OBJS) *.gc*

fclean:				clean
					$(RM) $(NAME) $(NAME)

re:					fclean all

.PHONY:				clean fclean re