/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** tna - name of all the teams
*/

#include "server.h"

bool start_tna(zappy_data_t *z, client_t *client, char *arg)
{
    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;

    (void)arg;
    for (int i = 0; i < z->data.nb_teams; i++) {
        add_data(&client->out, 2, "tna ", z->data.teams[i].name);
    }
    return (SUCCESS);
}

bool end_tna(zappy_data_t *z, client_t *client, char *arg)
{
    (void)*z;
    (void)*client;
    (void)arg;
    return (SUCCESS);
}