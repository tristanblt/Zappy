/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** egg_tools
*/

#include "server.h"

bool add_egg(zappy_data_t *z, char *team, position_t pos, int f)
{
    egg_t *new = malloc(sizeof(egg_t));

    if (new == NULL)
        return (ERROR);
    new->pos.x = pos.x;
    new->pos.y = pos.y;
    new->status = 600.0 / f;
    new->team = team;
    SLIST_INSERT_HEAD(&z->data.eggs, new, next);
    return (SUCCESS);
}

egg_t *get_egg_by_team(zappy_data_t *z, char *team)
{
    egg_t *tmp;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        if (!strcmp(tmp->team, team) && tmp->status == HATCHED)
            return (tmp);
    }
    return (NULL);
}

void assign_egg_to_client(zappy_data_t *z, client_t *client, egg_t *egg)
{
    ((c_data_t *)client->data)->pos.x = egg->pos.x;
    ((c_data_t *)client->data)->pos.y = egg->pos.y;
    ((c_data_t *)client->data)->team = egg->team;
    SLIST_REMOVE(&z->data.eggs, egg, egg_s, next);
    free(egg);
}

bool init_client_context(zappy_data_t *z, client_t *client, char *name)
{
    egg_t *egg = get_egg_by_team(z, name);
    team_t *team = get_team_by_name(z->data.teams, z->data.nb_teams, name);

    if (!team) {
        rm_client(z->server, client);
        return (ERROR);
    }
    if (team->nb == 0) {
        ((c_data_t *)client->data)->pos.x = rand() % z->data.map_width;
        ((c_data_t *)client->data)->pos.y = rand() % z->data.map_height;
        ((c_data_t *)client->data)->team = name;
    } else if (team->nb < z->data.nb_mates && egg)
        assign_egg_to_client(z, client, egg);
    else {
        rm_client(z->server, client);
        return (ERROR);
    }
    return (SUCCESS);
}