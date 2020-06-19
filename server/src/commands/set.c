/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** set
*/

#include "server.h"

bool start_set_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}