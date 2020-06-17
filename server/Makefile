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
					commands/broadcast.c \
					commands/connect_number.c \
					commands/death.c \
					commands/eject.c \
					commands/incantation.c \
					commands/move.c \
					commands/rotate.c \
					commands/inventory.c \
					commands/look.c \
					commands/look_tools.c \
					commands/set.c \
					commands/set_down.c \
					commands/take.c \
					protocole/bct.c \
					protocole/ebo.c \
					protocole/edi.c \
					protocole/mct.c \
					protocole/msz.c \
					protocole/pex.c \
					protocole/pin.c \
					protocole/plv.c \
					protocole/pnw.c \
					protocole/ppo.c \
					protocole/sbp.c \
					protocole/seg.c \
					protocole/smg.c \
					protocole/sst.c \
					protocole/suc.c \
					protocole/tna.c \
					tools/split.c \
					tools/data/data_tools.c \
					tools/data/egg_tools.c \
					tools/data/map_delete_tools.c \
					tools/data/map_setup_tools.c \
					tools/data/map_spawn_tools.c \
					tools/data/map_tools.c \
					tools/data/ressources_tools.c \
					tools/data/team_tools.c \
					tools/data/vector_tools.c \
					tools/input/args_tools.c \
					tools/input/init_param_tools.c \
					tools/input/param_tools.c \
					tools/input/signal_tools.c \
					tools/network/client_tools.c \
					tools/network/command_tools.c \
					tools/network/connexion_tools.c \
					tools/network/flux_tools.c \
					tools/network/request_tools.c \
					tools/network/server_tools.c \
					tools/network/time_tools.c \
					tools/zappy_tools.c \
					tools/display_usage.c \

SRCS			=	$(addprefix $(SRCPATH), $(SRCS_FILES))
OBJS			= 	$(SRCS:%.c=%.o)

UNAME_S	= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS	= 	-ldl -luuid -lm
else
	LDFLAGS	= 	-ldl
endif

CFLAGS			=	-W -Wall -Wextra -Wshadow	\
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