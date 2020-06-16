/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn int zappy_server(int ac, char **av)
 * \brief Fonction principale du projet, réunit réseau et applicatif
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \return 0 en succès et 84 en cas d'erreur
 */

int zappy_server(int ac, char **av)
{
    zappy_data_t *z;
    param_t param;
    bool is_ok = true;

    sigint_catch = false;
    signal(SIGINT, handle_sigint);
    if (game_param(ac, av, &param) == -1)
        return (EPI_EXIT_ERROR);
    if ((z = init_zappy(param)) == NULL)
        return (EPI_EXIT_ERROR);
    while (z->server->running) {
        is_ok = server_iteration(z->server);
        if (is_ok)
            is_ok = handle_commands(z);
        if (!is_ok || sigint_catch == true)
            z->server->running = false;
        update_map(z);
    }
    end_zappy(z, param);
    return (is_ok ? EPI_EXIT_ERROR : EPI_EXIT_SUCCESS);
}