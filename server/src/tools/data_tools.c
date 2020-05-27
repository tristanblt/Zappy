/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** data_tools
*/

#include "server.h"

void init_client_data(client_data_t *data, char *team, position_t pos)
{
    data->team = team;
    data->dir = rand() % 4;
    data->cool_down = 0;
    data->level = 1;
    data->pos.x = pos.x;
    data->pos.y = pos.y;
    init_ressources(data->inventory);
}

bool init_server_data(server_data_t *data, param_t params)
{
    int nb = 0;

    data->f = params.freq;
    data->map_height = params.height;
    data->map_width = params.width;
    data->nb_mates = params.clientNB;
    while (params.name[nb])
        nb++;
    if ((data->teams = malloc(sizeof(team_t) * nb)) == NULL)
        return (ERROR);
    for (int i = 0; i < nb; i++) {
        data->teams[i].name = params.name[i];
        data->teams[i].nb = 0;
    }
    data->nb_teams = nb;
    //// INIT MAP HERE
    return (SUCCESS);
}

void free_server_data(server_data_t *data)
{
    for (int i = 0; i < data->nb_teams; i++)
        free(data->teams[i].name);
    free(data->teams);
}