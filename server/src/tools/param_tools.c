/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn void init_param(int ac, char **av, param_t *param)
 * \brief Initialise la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \return void
 */

void init_param(int ac, char **av, param_t *param) {
    if ((ac == 2) && (strcmp(av[1], "-help") == 0)) {
        display_usage_s();
    } else {
        printf("param_t structure has not been initialized\n");
    }
    param->port = 8080;
}