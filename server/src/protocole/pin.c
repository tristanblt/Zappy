/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** pin - player's inventory
*/

#include "server.h"

bool start_pin(zappy_data_t *z, client_t *client, char *arg)
{
    client_t *tmp;
    c_data_t * data;

    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        data = (c_data_t *)tmp->data;
        if (data->idx == atoi(arg)) {
            add_data(&client->out, 11, "plv", int_to_char(data->idx),
            int_to_char(data->pos.x), int_to_char(data->pos.y),
            int_to_char((data->inventory.food / 126) / z->data.f),
            int_to_char(data->inventory.linemate),
            int_to_char(data->inventory.deraumere),
            int_to_char(data->inventory.sibur),
            int_to_char(data->inventory.mendiane),
            int_to_char(data->inventory.phiras),
            int_to_char(data->inventory.thystame));
        }
    }
    return (SUCCESS);
}

bool end_pin(zappy_data_t *z, client_t *client, char *arg)
{
    (void)*z;
    (void)*client;
    (void)arg;
    return (SUCCESS);
}