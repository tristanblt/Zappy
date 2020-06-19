/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** death
*/

#include "server.h"

void start_proceed_death(zappy_data_t *z, client_t *client)
{
    (void)z;
    ((c_data_t *)client->data)->is_alive = false;
    get_team_by_name(z->data.teams, z->data.nb_teams,
    ((c_data_t *)client->data)->team)->victory_count -=
    (((c_data_t *)client->data)->level - 1);
    add_data(&client->out, 1, "dead");
}

void end_proceed_death(zappy_data_t *z, client_t *client)
{
    team_t *team = get_team_by_name(z->data.teams, z->data.nb_teams,
    ((c_data_t *)client->data)->team);

    team->nb--;
    pdi(z->server, client);
    rm_client(z->server, client);
}

bool handle_life(zappy_data_t *z, client_t *client)
{
    if (client->type == GRAPHICAL)
        return (SUCCESS);
    if (((c_data_t *)client->data)->is_alive == false &&
    client->out.nb == 0) {
        end_proceed_death(z, client);
        return (false);
    }
    if (((c_data_t *)client->data)->inventory.food == 0)
        start_proceed_death(z, client);
    return (true);
}