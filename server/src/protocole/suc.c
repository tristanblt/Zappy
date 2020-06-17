/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** suc - unknown command
*/

#include "server.h"

bool start_sbp(zappy_data_t *z, client_t *client, char *arg)
{
    client_t *tmp;
        SLIST_FOREACH(tmp, &z->server->clients, next)
    {
            if ( tmp->type == "GRAPHICAL") {
                add_data(&tmp->out, 1, "suc");
        }
    }
        return (SUCCESS);
}
bool end_sbp(zappy_data_t *z, client_t *client, char *arg)
{
        return (SUCCESS);
}