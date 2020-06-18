/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** suc - unknown command
*/

#include "server.h"

bool suc(client_t *client)
{
    add_data(&client->out, 1, "suc");
    return (SUCCESS);
}