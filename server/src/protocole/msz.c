/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** msz - map size
*/

#include "server.h"

bool start_msz(zappy_data_t *z, client_t *client, char *arg)
{
    char buffer[6] = {0};

    (void)arg;
    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    add_raw_data(&client->out, "msz ");
    sprintf(buffer, "%d", z->data.map_sz.x);
    add_raw_data(&client->out, buffer);
    add_raw_data(&client->out, " ");
    sprintf(buffer, "%d", z->data.map_sz.y);
    add_raw_data(&client->out, buffer);
    add_raw_data(&client->out, "\r\n");
    return (SUCCESS);
}

bool end_msz(zappy_data_t *z, client_t *client, char *arg)
{
    (void)*z;
    (void)*client;
    (void)arg;
    return (SUCCESS);
}