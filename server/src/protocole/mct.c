/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** mct - content of the map (all the tiles)
*/

#include "server.h"

int mct(zappy_data_t *z, client_t *client, char *arg)
{
    char buffer[12] = {0};

    for (int y = 0; y < z->data.map_sz.y; y++) {
        for (int x  = 0; x < z->data.map_sz.x ; x++) {
            sprintf(buffer, "%d %d\n", x, y);
            bct(z, client, buffer);
        }
    }
    return (0);
}