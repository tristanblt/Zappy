/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** map_tools
*/

#include "server.h"

map_node_t *init_tile(void)
{
    map_node_t *tile = malloc(sizeof(map_node_t));

    if (!tile)
        return (NULL);
    tile->bottom = NULL;
    tile->left = NULL;
    tile->right = NULL;
    tile->top = NULL;
    return (tile);
}

map_node_t *create_line_circular(int size)
{
    map_node_t *tmp = init_tile();
    map_node_t *head;
    map_node_t *tile;

    if (!tmp)
        return (NULL);
    head = tmp;
    for (int i = 1; i < size; i++) {
        tile = init_tile();
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

void link_two_line(map_node_t *one, map_node_t *two, int size)
{
    map_node_t *tmp_one = one;
    map_node_t *tmp_two = two;

    for (int i = 0; i < size; i++) {
        tmp_one->bottom = tmp_two;
        tmp_two->top = tmp_one;
        tmp_one = tmp_one->right;
        tmp_two = tmp_two->right;
    }
}

map_node_t *create_map(int size)
{
    map_node_t *tmp = create_line_circular(size);
    map_node_t *head;
    map_node_t *line;

    if (!tmp)
        return (NULL);
    head = tmp;
    for (int i = 1; i < size; i++) {
        line = create_line_circular(size);

        if (!line)
            return (NULL);

        link_two_line(tmp, line, size);
        tmp = line;
    }
    link_two_line(line, head, size);
    return (head);
}