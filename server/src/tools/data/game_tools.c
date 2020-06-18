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
        if (z->data.teams[i].victory_count == 6) {
            seg(z, z->data.teams[i].name);
            z->data.end = true;
            break;
        }
    }
}