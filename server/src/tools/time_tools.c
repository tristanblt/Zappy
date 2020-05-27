/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** time_tools
*/

#include "server.h"

void init_time(time_manager_t *t)
{
    struct timespec ts;

    timespec_get(&ts, TIME_UTC);
    t->last_time = (double)clock() / CLOCKS_PER_SEC;
    t->delta_time = 1;
    t->is_needed = false;
    t->timeout.tv_sec = 0;
    t->timeout.tv_usec = 0;
}

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
        else if (tmp->data.cool_down != 0) {
            rm_from_request(tmp);
            tmp->data.cool_down = 0;
        }
    }
}

void update_timeout(server_t *server)
{
    client_t *tmp;
    float cd = -1;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (cd == -1 || cd > tmp->data.cool_down)
            cd = tmp->data.cool_down;
    }
    server->t.is_needed = (cd == 0) ? false : true;
    server->t.timeout.tv_sec = (long)cd;
    server->t.timeout.tv_usec = 1000 * (cd - (int)cd);
}

void handle_time(server_t *server)
{
    update_delta_time(server);
    update_cool_downs(server);
    update_timeout(server);
}