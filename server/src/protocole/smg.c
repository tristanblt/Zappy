/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** smg - message from the server
*/

#include "server.h"

bool smg(zappy_data_t *z, char *arg)
{
    client_t *tmp;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if( tmp->type == "GRAPHICAL") {
            add_data(&tmp->out, 2, "smg ", arg);
        }
    }
    return (SUCCESS);
}