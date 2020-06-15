/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** eject
*/

#include "server.h"

bool start_eject_cmd(zappy_data_t *z, client_t *client, char *command)
{
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}

bool end_eject_cmd(zappy_data_t *z, client_t *client, char *command)
{
    client_t *tmp;
    bool ejected = false;

    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (((c_data_t *)client->data)->pos.x == ((c_data_t *)tmp->data)->pos.x &&
        ((c_data_t *)client->data)->pos.y == ((c_data_t *)tmp->data)->pos.y) {
            move_in_dir(tmp, ((c_data_t *)client->data)->dir,
            z->data.map_sz);
            add_data(&tmp->out, 2, "eject: ",
            int_to_char(compute_direction(((c_data_t *)client->data)->pos,
            ((c_data_t *)tmp->data)->pos, z->data.map_sz,
            ((c_data_t *)tmp->data)->dir)));
            ejected = true;
        }
    }
    if (ejected)
        add_data(&client->out, 1, "ok");
    else
        add_data(&client->out, 1, "ko");
    return (SUCCESS);
}