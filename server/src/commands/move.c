/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** move
*/

#include "server.h"

bool start_move_cmd(zappy_data_t *z, client_t *client, char *command)
{
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}

bool end_move_cmd(zappy_data_t *z, client_t *client, char *command)
{
    switch (((c_data_t *)client->data)->dir) {
    case N:
        ((c_data_t *)client->data)->pos.y--;
        break;
    case E:
        ((c_data_t *)client->data)->pos.x--;
        break;
    case S:
        ((c_data_t *)client->data)->pos.y++;
        break;
    case W:
        ((c_data_t *)client->data)->pos.x++;
        break;
    default:
        break;
    }
    add_data(&client->out, 1, "ok");
    return (SUCCESS);
}