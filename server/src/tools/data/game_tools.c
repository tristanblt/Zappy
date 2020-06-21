/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** game_tools
*/

#include "server.h"

void handle_end_game(zappy_data_t *z)
{
    for (int i = 0; i < z->data.nb_teams; i++) {
        if (z->data.teams[i].victory_count == 7 * 6) {
            seg(z, z->data.teams[i].name);
            z->data.end = FINAL;
            break;
        }
    }
}

char *determine_winner(zappy_data_t *z)
{
    int best = -1;
    int tmp = -1;

    for (int i = 0; i < z->data.nb_teams; i++) {
        if (best == -1 || best < z->data.teams[i].victory_count) {
            best = z->data.teams[i].victory_count;
            tmp = i;
        }
    }
    if (best == -1)
        return ("");
    return (z->data.teams[tmp].name);
}

bool every_end_messages_sent(zappy_data_t *z)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL && tmp->out.nb)
            return (false);
    }
    return (true);
}

int nb_graphical(server_t *server)
{
    client_t *tmp;
    int nb = 0;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            nb++;
    }
    return (nb);
}

void level_up(server_t *server, position_t pos)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == AI && ((c_data_t *)tmp->data)->pos.x == pos.x &&
        ((c_data_t *)tmp->data)->pos.y == pos.y) {
            ((c_data_t *)tmp->data)->level++;
            add_data(&tmp->out, 2, "Current level:",
            int_to_char(((c_data_t *)tmp->data)->level));
        }
    }
}