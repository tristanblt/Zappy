/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** time_tools
*/

#include "server.h"

void init_time(time_manager_t *t, int ratio)
{
    struct timespec ts;

    timespec_get(&ts, TIME_UTC);
    t->last_time = (double)clock() / CLOCKS_PER_SEC;
    t->delta_time = 1;
    t->is_needed = false;
    t->timeout.tv_sec = 0;
    t->timeout.tv_usec = 0;
    t->ratio = ratio;
}

void update_delta_time(time_manager_t *t)
{
    struct timespec ts;
    double tmp = t->last_time;

    timespec_get(&ts, TIME_UTC);
    t->last_time = (double)clock() / CLOCKS_PER_SEC;
    t->delta_time = (t->last_time - tmp);
}

void update_cool_downs(server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (((c_data_t *)tmp->data)->cool_down - server->t.delta_time > 0)
            ((c_data_t *)tmp->data)->cool_down -= server->t.delta_time;
        else if (((c_data_t *)tmp->data)->cool_down != 0) {
            rm_from_request(tmp);
            ((c_data_t *)tmp->data)->cool_down = 0;
        }
        if (((c_data_t *)tmp->data)->hunger_cd - server->t.delta_time > 0)
            ((c_data_t *)tmp->data)->hunger_cd -= server->t.delta_time;
        else {
            ((c_data_t *)tmp->data)->inventory.food--;
            ((c_data_t *)tmp->data)->hunger_cd = 126 / server->t.ratio;
        }
    }
}

void update_timeout(server_t *server)
{
    client_t *tmp;
    float cd = -1;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (cd == -1 || cd > ((c_data_t *)tmp->data)->cool_down)
            cd = ((c_data_t *)tmp->data)->cool_down;
    }
    server->t.is_needed = (cd == 0) ? false : true;
    server->t.timeout.tv_sec = (long)cd;
    server->t.timeout.tv_usec = 1000 * (cd - (int)cd);
}

void handle_time(server_t *server)
{
    update_delta_time(&server->t);
    update_cool_downs(server);
    update_timeout(server);
}