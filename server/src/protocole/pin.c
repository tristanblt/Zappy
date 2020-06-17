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
    int food;
    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (((c_data_t *)tmp->data)->idx == atoi(arg)) {
            food = (((c_data_t *)tmp->data)->inventory.food / 126) / z->data.f;
            add_data(&client->out, 4, "plv ",
            int_to_char(((c_data_t *)tmp->data)->idx), " ",
            int_to_char(((c_data_t *)tmp->data)->pos.x), " ",
            int_to_char(((c_data_t *)tmp->data)->pos.y), " ",
            int_to_char(food), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.linemate), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.deraumere), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.sibur), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.mendiane), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.phiras), " ",
            int_to_char(((c_data_t *)tmp->data)->inventory.thystame));
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