/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** time_tools
*/

#include "server.h"

void update_delta_time(server_t *server)
{
    struct timespec ts;
    double tmp = server->t.last_time;

    timespec_get(&ts, TIME_UTC);
    server->t.last_time = (double)clock() / CLOCKS_PER_SEC;
    server->t.delta_time = (server->t.last_time - tmp);
}