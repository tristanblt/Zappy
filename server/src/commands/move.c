/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** move
*/

#include "server.h"

bool start_move_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}

bool end_move_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    move_in_dir(client, ((c_data_t *)client->data)->dir, z->data.map_sz);
    add_data(&client->out, 1, "ok");
    return (SUCCESS);
}