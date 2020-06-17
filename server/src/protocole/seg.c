/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** seg - end of game
*/

#include "server.h"

bool seg(zappy_data_t *z, char *team_name)
{
    client_t *tmp;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if( tmp->type == "GRAPHICAL") {
            add_data(&tmp->out, 2, "seg ", team_name);
        }
    }
    return (SUCCESS);
}