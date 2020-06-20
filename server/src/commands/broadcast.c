/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** broadcast
*/

#include "server.h"

bool start_broadcast_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}

bool end_broadcast_cmd(zappy_data_t *z, client_t *client, char *command)
{
    client_t *tmp;

    (void)command;
    add_data(&client->out, 1, "ok");
    pbc(z->server, client, command);
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp != client && tmp->type == AI) {
            add_data(&tmp->out, 4, "message",
            int_to_char(compute_direction(((c_data_t *)client->data)->pos,
            ((c_data_t *)tmp->data)->pos, z->data.map_sz,
            ((c_data_t *)tmp->data)->dir)), ", ", command);
        }
    }
    return (SUCCESS);
}