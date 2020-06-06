/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** vector_tools
*/

#include "server.h"

const float angles[8][2] = {{19.47, 340.53}, {340.53, 289.47},
    {289.47, 250.53}, {250.53, 199.47}, {199.47, 160.53},
    {160.53, 109.47}, {109.47, 70.53}, {70.43, 19.47}};

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
    position_t dist = get_smallest_distance(sender, reciever, w, h);
    float angle = atan2f((float)dist.x, (float)dist.y) * (180 / 3.14159265);

    for (int i = 0; i < 8; i++) {
        if ((i == 0 && angles[i][0] >= angle || angles[i][1] <= angle) ||
            angles[i][0] >= angle && angles[i][1] <= angle)
            return (i + 1);
    }
    return (0);
}