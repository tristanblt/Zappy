/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** vector_tools
*/

#include "server.h"

int graph_value(int size, int value)
{
    if (value >= 0)
        return (value % size);
    return (size - (value % size));
}

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

int compute_direction(position_t sender, position_t reciever, int w, int h)
{
    position_t dist = get_smallest_distance(p1, p2, width, height);
    float angle = 

}