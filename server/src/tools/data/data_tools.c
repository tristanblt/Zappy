/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** data_tools
*/

#include "server.h"

void init_client_data(c_data_t *data, char *team, position_t pos)
{
    data->team = team;
    data->dir = rand() % 4;
    data->cool_down = 0;
    data->level = 1;
    data->pos.x = pos.x;
    data->pos.y = pos.y;
    init_ressources(&data->inventory);
    data->inventory.food = 10;
}

bool init_server_data(s_data_t *data, param_t params)
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
    if (!(data->map = create_map((position_t){params.width, params.height}))) {
        free(data->teams);
        return (ERROR);
    }
    return (SUCCESS);
}

void free_server_data(s_data_t *data)
{
    for (int i = 0; i < data->nb_teams; i++)
        free(data->teams[i].name);
    free_map(data->map, (position_t){data->map_width, data->map_height});
    free(data->teams);
}