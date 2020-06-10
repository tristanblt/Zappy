/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** msz - map size
*/

#include "server.h"

int msz(zappy_data_t *z, client_t *client, char *arg)
{
    char buffer[6] = {0};

    add_raw_data(&client->out, "msz ");
    sprintf(buffer, "%d", z->data.map_width);
    add_raw_data(&client->out, buffer);
    add_raw_data(&client->out, " ");
    sprintf(buffer, "%d", z->data.map_height);
    add_raw_data(&client->out, buffer);
    add_raw_data(&client->out, "\n");
}