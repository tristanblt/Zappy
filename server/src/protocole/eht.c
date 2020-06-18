/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** eht
*/

#include "server.h"

void eht(server_t *server, egg_t *egg)
{
    client_t *tmp;
    char nb[12] = {0};

    sprintf(nb, "%i", egg->idx);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 2 ,"eht", nb);
    }
}