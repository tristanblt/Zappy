/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** vector_tools
*/

#include "server.h"

const float angles[8][2] = {{16.1, 343.9}, {343.9, 286.1},
    {286.1, 253.9}, {253.6, 196.1}, {196.1, 163.9},
    {163.9, 106.1}, {106.1, 73.9}, {73.9, 16.1}};

const int cases[8][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {3, 5, 7, 1},
    {4, 6, 8, 2}, {5, 7, 1, 3}, {6, 8, 2, 4}, {7, 1, 3, 5}, {8, 2, 4, 6}};

/**
 * \fn position_t get_smallest_distance(position_t p1, position_t p2, int w,
 * int h)
 * \brief Fonction qui retourne la distance la plus courte entre deux tiles
 *
 * \param p1 la tile emetrice
 * \param p2 la tile receptrice
 * \param w width de la map
 * \param h height de la map
 * \return la distance la plus courte
 */
position_t get_smallest_distance(position_t p1, position_t p2, int w, int h)
{
    position_t ret = {0, 0};

    if (abs(p1.x - p2.x) > w / 2)
        ret.x = (w - abs(p1.x - p2.x)) * (p1.x - p2.x > 0 ? 1 : -1);
    else
        ret.x = p1.x - p2.x;
    if (abs(p1.y - p2.y) > h / 2)
        ret.y = (h - abs(p1.y - p2.y)) * (p1.y - p2.y > 0 ? 1 : -1);
    else
        ret.y = p1.y - p2.y;
    return (ret);
}

/**
 * \fn int compute_direction(position_t sender, position_t reciever, int w,
 * int h)
 * \brief Fonction qui récupère la direction de 1 à 8
 *
 * \param sender la ou l'emmeteur est positionné
 * \param reciever la ou le recever est positionné
 * \param w width de la map
 * \param h height de la map
 * \return la direction de 1 à 8, 0 en cas d'erreur
 */
int compute_direction(position_t sender, position_t reciever, position_t map,
int dir)
{
    position_t dist = get_smallest_distance(sender, reciever, map.x, map.y);
    float angle = atan2f((float)dist.x, (float)dist.y) * (180 / 3.14159265);
    if (angle < 0)
        angle += 360;
    if (dist.x == 0 && dist.y == 0)
        return (0);
    for (int i = 0; i < 8; i++) {
        if ((i == 0 && (angles[i][0] >= angle || angles[i][1] <= angle)) ||
            (angles[i][0] >= angle && angles[i][1] <= angle)) {
            printf("angle: %f° direction: %i\n",angle, cases[i][dir - 1]);
            return (cases[i][dir - 1]);
        }
    }
    return (0);
}