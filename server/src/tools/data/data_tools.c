/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** data_tools
*/

#include "server.h"

c_data_t *init_client_data(void)
{
    c_data_t *new = malloc(sizeof(c_data_t));

    if (!new)
        return (NULL);
    new->team = NULL;
    new->dir = rand() % 4;
    new->cool_down = 0;
    new->level = 1;
    new->pos.x = 0;
    new->pos.y = 0;
    init_ressources(&new->inventory);
    new->inventory.food = 10;
    return (new);
}

bool init_server_data(s_data_t *data, param_t params)
{
    int nb = 0;

    data->f = params.freq;
    data->map_height = params.height;
    data->map_width = params.width;
    data->nb_mates = params.clientNB;
    SLIST_INIT(&data->eggs);
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
    egg_t *tmp;

    while (!SLIST_EMPTY(&data->eggs)) {
        tmp = SLIST_FIRST(&data->eggs);
        SLIST_REMOVE_HEAD(&data->eggs, next);
        free(tmp);
    }
    for (int i = 0; i < data->nb_teams; i++)
        free(data->teams[i].name);
    free_map(data->map, (position_t){data->map_width, data->map_height});
    free(data->teams);
}