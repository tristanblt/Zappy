/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    srand(time(NULL));
    return (zappy_server(ac, av));
}