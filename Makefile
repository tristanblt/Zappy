##
## EPITECH PROJECT, 2020
## PSU_zappy_2019
## File description:
## Makefile
##

all:
	make -C server/

re:
	make re -C server/

clean:
	make clean -C server/

fclean:
	make fclean -C server/


.PHONY:	clean fclean re