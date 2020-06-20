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
    (int)(tile->ressources.food) + tile->ressources.linemate +
    tile->ressources.sibur + tile->ressources.mendiane +
    tile->ressources.phiras + tile->ressources.thystame);
}

void spawn_ressources_on_tile(map_node_t *tile)
{
    int nb_to_spawn = rand() % 4;
    int res;

    if (rand() % 101 > 35 && nb_res_on_tile(tile) < 40)
        return;
    for (int i = 0; i < nb_to_spawn; i++) {
        res = rand() % 14;
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
    z->data.spawn_cd = 200 / z->data.f;
    for (int y = 0; y < z->data.map_sz.y; y++) {
        for (int x = 0; x < z->data.map_sz.x; x++) {
            spawn_ressources_on_tile(tmp);
            tmp = tmp->right;
        }
        tmp = tmp2->top;
        tmp2 = tmp;
    }
}