/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** signal_tools
*/

#include "server.h"

/**
 * \fn void handle_sigint()
 * \brief Pour gérer le ctrl c
 *
 * \return rien
 */

void handle_sigint()
{
    sigint_catch = true;
}