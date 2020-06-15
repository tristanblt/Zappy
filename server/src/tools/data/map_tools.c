/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** map_tools
*/

#include "server.h"

/**
 * \fn map_node_t *on_tile(map_node_t *start, int x, int y)
 * \brief Fonction qui récupère la map aux coordonnées données
 *
 * \param start corrspond à la tile 0 0
 * \param x la position en largeur
 * \param y la position en hauteur de la tile
 * \return la tile demandée (attention peu bouclinf si les coordonées ne
 * sont pas bonnes)
 */
map_node_t *on_tile(map_node_t *start, int x, int y)
{
    map_node_t *pos = start;

    while (pos->coordinates.x != x)
        pos = pos->right;
    while (pos->coordinates.y != y)
        pos = pos->bottom;
    return (pos);
}

/**
 * \fn int graph_value(int size, int value)
 * \brief Fonction qui set un axe de coordonée dan l'intervalle [0:size]
 *
 * \param size la taille de l'axe
 * \param value la valeur de la coordonée
 * \return la nouvelle valeur de la coordonée
 */
int graph_value(int size, int value)
{
    if (value >= 0)
        return (value % size);
    return (size + (value % size));
}

/**
 * \fn int count_players(server_t *server, int x, int y)
 * \brief Fonction qui compte les joueurs sur une case
 *
 * \param server le server contenant tous les clients
 * \param x la position en largeur de la tile
 * \param y la position en hauteur de la tile
 * \return le nombre de clients sur la case
 */
int count_players(server_t *server, int x, int y)
{
    client_t *tmp;
    int cnt = 0;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (((c_data_t *)tmp->data)->pos.x == x &&
            ((c_data_t *)tmp->data)->pos.y == y)
            cnt++;
    }
    return (cnt);
}

/**
 * \fn extracted_content_t get_tile_content(s_data_t *data, server_t *s, int x,
 * int y)
 * \brief Fonction qui retourne les ressources et le nombre de joueurs sur une
 * tile
 *
 * \param data data du programme dont la map et ses informations
 * \param s le server
 * \param x la position en largeur de la tile
 * \param y la position en hauteur de la tile
 * \return une nouvelle tile
 */
extracted_content_t get_tile_content(s_data_t *data, server_t *s, int x, int y)
{
    extracted_content_t content;
    int true_x = graph_value(data->map_sz.x, x);
    int true_y = graph_value(data->map_sz.y, y);

    content.ressources = &on_tile(data->map, true_x, true_y)->ressources;
    content.nb_player = count_players(s, x, y);
    return (content);
}

void move_in_dir(client_t *client, int dir, position_t map_sz)
{
    switch (dir) {
    case N:
        ((c_data_t *)client->data)->pos.y =
        graph_value(map_sz.y, ((c_data_t *)client->data)->pos.y - 1);
        break;
    case E:
        ((c_data_t *)client->data)->pos.x =
        graph_value(map_sz.x, ((c_data_t *)client->data)->pos.x - 1);
        break;
    case S:
        ((c_data_t *)client->data)->pos.y =
        graph_value(map_sz.y, ((c_data_t *)client->data)->pos.y + 1);
        break;
    case W:
        ((c_data_t *)client->data)->pos.x =
        graph_value(map_sz.x, ((c_data_t *)client->data)->pos.x + 1);
        break;
    default:
        break;
    }
}