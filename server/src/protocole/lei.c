/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** lei
*/

#include "server.h"

void add_egg_info(flux_t *flux, egg_t *tmp)
{
    char nb[12] = {0};

    sprintf(nb, "%i", tmp->idx);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    sprintf(nb, "%i", tmp->pos.x);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    sprintf(nb, "%i", tmp->pos.y);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    add_raw_data(flux, " ");
    add_raw_data(flux, tmp->team);
    add_raw_data(flux, ",");
}

void add_eggs_info(flux_t *flux, zappy_data_t *z)
{
    egg_t *tmp;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        add_egg_info(flux, tmp);
    }
}

bool start_lei_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    return (SUCCESS);
}

bool end_lei_cmd(zappy_data_t *z, client_t *client, char *arg)
{
    (void)arg;
    add_raw_data(&client->out, "lei");
    add_eggs_info(&client->out, z);
    add_raw_data(&client->out, "\r\n");
    return (SUCCESS);
}
