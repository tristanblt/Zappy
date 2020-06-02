/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** map_tools
*/

#include "server.h"

map_node_t *on_tile(map_node_t *start, int x, int y)
{
    map_node_t *pos = start;

    while (pos->coordinates.x != x)
        pos = pos->right;
    while (pos->coordinates.y != y)
        pos = pos->bottom;
    return (pos);
}

int graph_value(int size, int value)
{
    if (value > 0)
        return (value % size);
    return (size - (value % size));
}

int count_players(server_t *server, int x, int y)
{
    client_t *tmp;
    int cnt = 0;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (tmp->data.pos.x == x && tmp->data.pos.y == y)
            cnt++;
    }
    return (cnt);
}

extracted_content_t get_tile_content(server_t *server, int x, int y)
{
    extracted_content_t content;
    int true_x = graph_value(server->data.map_width, x);
    int true_y = graph_value(server->data.map_height, y);

    content.ressources = on_tile(server->data.map, true_x, true_y)->ressources;
    content.nb_player = count_players(server, x, y);
    return (content);
}