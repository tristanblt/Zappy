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

void update_cool_downs(server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (tmp->data.cool_down - server->t.delta_time > 0)
            tmp->data.cool_down -= server->t.delta_time;
        else
            tmp->data.cool_down = 0;
    }
}

void handle_time(server_t *server)
{
    update_delta_time(server);
    update_cool_downs(server);
}