/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** map_spawn_tools
*/

#include "server.h"

void add_ressource(ressources_t *res, int type)
{
    if (type == 0)
        res->food++;
    if (type == 1)
        res->deraumere++;
    if (type == 2)
        res->linemate++;
    if (type == 3)
        res->mendiane++;
    if (type == 4)
        res->phiras++;
    if (type == 5)
        res->sibur++;
    if (type == 6)
        res->thystame++;
}

int nb_res_on_tile(map_node_t *tile)
{
    return (tile->ressources.deraumere +
    tile->ressources.food + tile->ressources.linemate +
    tile->ressources.sibur + tile->ressources.mendiane +
    tile->ressources.phiras + tile->ressources.thystame);
}

void spawn_ressources_on_tile(map_node_t *tile, server_t *server)
{
    int nb_to_spawn = 1 + rand() % 2;
    int res;

    if (rand() % 101 > 40 && nb_res_on_tile(tile) < 10 &&
        is_player_free(tile->coordinates, server))
        return;
    for (int i = 0; i < nb_to_spawn; i++) {
        res = rand() % 28;
        if (res < 6)
            res++;
        else
            res = 0;
        add_ressource(&tile->ressources, res);
    }
}

void update_map(zappy_data_t *z)
{
    map_node_t *tmp = z->data.map;
    map_node_t *tmp2 = z->data.map;

    if (z->data.spawn_cd - z->server->t.delta_time > 0) {
        z->data.spawn_cd -= z->server->t.delta_time;
        return;
    }
    z->data.spawn_cd = 600 / z->data.f;
    for (int y = 0; y < z->data.map_sz.y; y++) {
        for (int x = 0; x < z->data.map_sz.x; x++) {
            spawn_ressources_on_tile(tmp, z->server);
            tmp = tmp->right;
        }
        tmp = tmp2->top;
        tmp2 = tmp;
    }
}

map_node_t *get_tile(map_node_t *map, int x, int y, s_data_t server)
{
    map_node_t *tmp = map;

    for (int i = 0; i < server.map_sz.y; i++) {
        if (tmp->coordinates.y == y)
            break;
        tmp = tmp->bottom;
    }
    if (tmp->coordinates.y != y)
        return (NULL);
    for (int j = 0; j < server.map_sz.x; j++) {
        if (tmp->coordinates.x == x)
            return (tmp);
        tmp = tmp->right;
    }
    return (NULL);
}