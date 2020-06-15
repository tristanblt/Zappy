/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_delete_tools
*/

#include "server.h"

/**
 * \fn void delete_line_tile(map_node_t *line)
 * \brief Permet de free une ligne de la map circulaire ou pas
 *
 * \param line la head de la ligne de tile
 * \return rien
 */
void delete_line_tile(map_node_t *line)
{
    if (line->left)
        line->left->right = NULL;
    for (map_node_t *tmp = line; line; tmp = line->right) {
        if (line)
            free(line);
        line = tmp;
    }
}

/**
 * \fn void delete_map_tile(map_node_t *map)
 * \brief Permet de free une map circulaire ou pas
 *
 * \param line la head de la map
 * \return rien
 */
void delete_map_tile(map_node_t *map)
{
    if (map->top)
        map->top->bottom = NULL;
    for (map_node_t *tmp = map; map; tmp = map->bottom) {
        if (map)
            delete_line_tile(map);
        map = tmp;
    }
}

/**
 * \fn void free_map(map_node_t *map, position_t size)
 * \brief Permet de free une map circulaire
 *
 * \param size la taille maximum de la map
 * \return rien
 */
void free_map(map_node_t *map, position_t size)
{
    map_node_t *tmp = map;
    map_node_t *next_bottom;
    map_node_t *next_right;

    for (int x = 0; x < size.x; x++) {
        next_bottom = tmp->bottom;
        for (int y = 0; y < size.y; y++) {
            next_right = tmp->right;
            if (tmp) {
                free(tmp);
            }
            tmp = next_right;
        }
        tmp = next_bottom;
    }
}