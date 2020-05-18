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
    param_t param;
    server_t *server = check(ac, av) == OK ? init_server(av[1]) : NULL;
    bool is_ok = true;

    sigint_catch = false;
    signal(SIGINT, handle_sigint);
    init_param(ac, av, &param);
    while (server->running) {
        is_ok = server_iteration(server);
        if (is_ok)
            is_ok = handle_commands(server);
        if (!is_ok || sigint_catch == true)
            server->running = false;
    }
    end_server(server);
    return (is_ok ? EPI_EXIT_ERROR : EPI_EXIT_SUCCESS);
}