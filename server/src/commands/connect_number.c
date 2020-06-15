/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** connect_number
*/

#include "server.h"

bool start_co_nbr_cmd(zappy_data_t *z, client_t *client, char *command)
{
    ((c_data_t *)client->data)->cool_down = 0;
    return (SUCCESS);
}

bool end_co_nbr_cmd(zappy_data_t *z, client_t *client, char *command)
{
    team_t *team = get_team_by_name(z->data.teams, z->data.nb_teams,
    ((c_data_t *)client->data)->team);

    if (!team)
        return (ERROR);
    add_data(&client->out, 1, int_to_char(z->data.nb_mates - team->nb));
    return (SUCCESS);
}