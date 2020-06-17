/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** map_tools
*/

#include "server.h"


void init_pos(position_t *pos, int x, int y)
{
    pos->x = x;
    pos->y = y;
}

/**
 * \fn map_node_t *init_tile(int x, int y)
 * \brief Fonction qui permet d'initialiser une tile de la map
 *
 * \param x la position en largeur de la tile
 * \param y la position en hauteur de la tile
 * \return une nouvelle tile
 */
map_node_t *create_tile(int x, int y)
{
    map_node_t *tile = malloc(sizeof(map_node_t));

    if (!tile)
        return (NULL);
    tile->bottom = NULL;
    tile->left = NULL;
    tile->right = NULL;
    tile->top = NULL;
    init_pos(&tile->coordinates, x, y);
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
    map_node_t *tmp = create_tile(x, 0);
    map_node_t *head;
    map_node_t *tile;

    if (!tmp)
        return (NULL);
    head = tmp;
    for (int y = 1; y < size.y; y++) {
        tile = create_tile(x, y);
        if (!tile) {
            delete_line_tile(head);
            return (NULL);
        }
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
        if (!line) {
            delete_map_tile(head);
            return (NULL);
        }
        link_two_line(tmp, line, size);
        tmp = line;
    }
    link_two_line(line, head, size);
    map_node_t *test = head;
    printf("x = %i, y = %i\n", test->coordinates.x, test->coordinates.y);
    printf("%p\n", test);
    test = test->right;
    printf("x = %i, y = %i\n", test->coordinates.x, test->coordinates.y);
    printf("%p\n", test);
    return (head);
}