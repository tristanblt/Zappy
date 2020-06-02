/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** map_tools
*/

#include "server.h"

/**
 * \fn map_node_t *init_tile(int x, int y)
 * \brief Fonction qui permet d'initialiser une tile de la map
 *
 * \param x la position en largeur de la tile
 * \param y la position en hauteur de la tile
 * \return une nouvelle tile
 */
map_node_t *init_tile(int x, int y)
{
    map_node_t *tile = malloc(sizeof(map_node_t));

    if (!tile)
        return (NULL);
    tile->bottom = NULL;
    tile->left = NULL;
    tile->right = NULL;
    tile->top = NULL;
    tile->coordinates.x = x;
    tile->coordinates.y = y;
    init_ressources(&tile->ressources);
    return (tile);
}

/**
 * \fn map_node_t *create_line_circular(position_t size, int x)
 * \brief Créer une ligne horizontal de tile pour la création de la map
 *
 * \param size la taille maximum de la map
 * \param x la position actuelle de cette ligne
 * \return la tête de la nouvelle ligne de la map
 */
map_node_t *create_line_circular(position_t size, int x)
{
    map_node_t *tmp = init_tile(x, 0);
    map_node_t *head;
    map_node_t *tile;

    if (!tmp)
        return (NULL);
    head = tmp;
    for (int y = 1; y < size.y; y++) {
        tile = init_tile(x, y);
        if (!tile)
            return (NULL);
        tmp->right = tile;
        tile->left = tmp;

        tmp = tile;
    }
    tile->right = head;
    head->left = tile;
    return (head);
}

/**
 * \fn void link_two_line(map_node_t *one, map_node_t *two, position_t size)
 * \brief Permet de lier deux lignes entre elle de manière circulaire
 *
 * \param one la première ligne à lier (ligne du haut)
 * \param two la deuxième ligne à lier (ligne du bas)
 * \param size la taille maximum de la map
 * \return rien
 */
void link_two_line(map_node_t *one, map_node_t *two, position_t size)
{
    map_node_t *tmp_one = one;
    map_node_t *tmp_two = two;

    for (int i = 0; i < size.x; i++) {
        tmp_one->bottom = tmp_two;
        tmp_two->top = tmp_one;
        tmp_one = tmp_one->right;
        tmp_two = tmp_two->right;
    }
}

/**
 * \fn map_node_t *create_map(position_t size)
 * \brief Créer la map
 *
 * \param size la taille maximum de la map
 * \return la map, un pointeur sur la head de la map
 */
map_node_t *create_map(position_t size)
{
    map_node_t *tmp = create_line_circular(size, 0);
    map_node_t *head;
    map_node_t *line;

    if (!tmp)
        return (NULL);
    head = tmp;
    for (int x = 1; x < size.x; x++) {
        line = create_line_circular(size, x);

        if (!line)
            return (NULL);

        link_two_line(tmp, line, size);
        tmp = line;
    }
    link_two_line(line, head, size);
    return (head);
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
            if (tmp)
                free(tmp);
            tmp = next_right;
        }
        tmp = next_bottom;
    }
}