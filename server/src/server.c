/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

void proceed_final(zappy_data_t *z)
{
    static int phase = 1;

    if (phase == 1) {
        seg(z, determine_winner(z));
        phase = 2;
        if (nb_graphical(z->server) == 0)
            z->server->state = ENDED;
    } else if (phase == 2) {
        if (every_end_messages_sent(z))
            z->server->state = ENDED;
    }
}

zappy_data_t *init_zappy_server(int ac, char **av, param_t *param)
{
    zappy_data_t *z;

    if (param == NULL)
        return (ERROR);
    sigint_catch = false;
    signal(SIGINT, handle_sigint);
    if (game_param(ac, av, param) == -1)
        return (NULL);
    if ((z = init_zappy(*param)) == NULL)
        return (NULL);
    return (z);
}

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
    param_t *param = malloc(sizeof(param_t));
    bool is_ok = true;

    if ((z = init_zappy_server(ac, av, param)) == NULL)
        return (EPI_EXIT_ERROR);
    while (z->server->state != ENDED) {
        if (sigint_catch == true && z->server->state == RUNNING) {
            z->server->state = FINAL;
        } else
            is_ok = server_iteration(z->server, get_lowest_egg_cd(z));
        if (is_ok && z->server->state == RUNNING)
            is_ok = handle_commands(z);
        else if (is_ok && z->server->state == FINAL)
            proceed_final(z);
        if (!is_ok)
            break;
        update_map(z);
    }
    end_zappy(z, param);
    return (!is_ok ? EPI_EXIT_ERROR : EPI_EXIT_SUCCESS);
}