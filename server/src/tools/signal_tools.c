/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** signal_tools
*/

#include "server.h"

void handle_sigint()
{
    sigint_catch = true;
}