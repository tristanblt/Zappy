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

    return (value % size²);
}

int count_players(server_t *server, int x, int y)
{
    client_t *tmp;
    int cnt = 0;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (((c_data_t *)tmp->data)->pos.x == x &&
            ((c_data_t *)tmp->data)->pos.y == y)
            cnt++;
    }
    return (cnt);
}

extracted_content_t get_tile_content(s_data_t *data, server_t *s, int x, int y)
{
    extracted_content_t content;
    int true_x = graph_value(data->map_width, x);
    int true_y = graph_value(data->map_height, y);

    content.ressources = &on_tile(data->map, true_x, true_y)->ressources;
    content.nb_player = count_players(s, x, y);
    return (content);
}