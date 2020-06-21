/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** tools
*/

#include "server.h"

bool end_handle_fds(server_t *server, bool is_ok)
{
    if (is_ok == ERROR || !server)
        return (ERROR);
    if (FD_ISSET(server->sck.fd, &server->fds.read) > 0)
        is_ok = new_client_welcome(server, init_client_data(server->t.ratio));
    if (!server || !is_ok || FD_ISSET(server->sck.fd, &server->fds.error) > 0)
        return (ERROR);
    return (is_ok);
}

bool check_team_compare(param_t *param, int i)
{
    for (int y = i + 1; param->name[y] != NULL; y++) {
        if (strcmp(param->name[i], param->name[y]) == 0)
            return (true);
    }
    return (false);
}

bool has_won(char *name, server_t *server)
{
    int nb = 0;
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == AI && !strcmp(name, ((c_data_t *)tmp->data)->team)
            && ((c_data_t *)tmp->data)->level == 8)
            nb++;
    }
    return (nb >= 6 ? true : false);
}

bool is_player_free(position_t pos, server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (pos.x == ((c_data_t *)tmp->data)->pos.x &&
            pos.y == ((c_data_t *)tmp->data)->pos.y)
            return (false);
    }
    return (true);
}