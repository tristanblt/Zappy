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
    add_raw_data(flux, " ");
    if (tmp->status == HATCHED)
        add_raw_data(flux, "1");
    else
        add_raw_data(flux, "0");
    add_raw_data(flux, "\r\n");
}

void add_eggs_info(flux_t *flux, zappy_data_t *z)
{
    egg_t *tmp;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        add_raw_data(flux, "lei");
        add_egg_info(flux, tmp);
    }
}

bool end_lei(zappy_data_t *z, client_t *client, char *command)
{
    (void)z;
    (void)client;
    (void)command;
    return (SUCCESS);
}

bool start_lei(zappy_data_t *z, client_t *client, char *arg)
{
    (void)arg;
    add_eggs_info(&client->out, z);
    return (SUCCESS);
}
