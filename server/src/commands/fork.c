/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** fork
*/

#include "server.h"

bool start_fork_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 42.0 / z->data.f;
    pfk(z->server, client);
    return (SUCCESS);
}

bool end_fork_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    if (add_egg(z, client, ((c_data_t *)client->data)->pos) == ERROR)
        return (ERROR);
    add_data(&client->out, 1, "ok");
    return (SUCCESS);
}