/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn void game_param(int ac, char **av, param_t *param)
 * \brief Envoie vers la fonctions adaptée a/aux arguments
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return void
 */

int game_param(int ac, char **av, param_t *param)
{
    if ((ac == 2) && (strcmp(av[1], "-help") == 0)) {
        display_usage_s();
    } else {
        init_param(param);
        if (check_param_n(ac, av, param) == -1) {
            display_usage_s();
            return (-1);
        }
        if (check_param(ac, av, param) == -1) {
            display_usage_s();
            return (-1);
        }
    }
    return (0);
}

/**
 * \fn void check_param(int ac, char **av, param_t *param);
 * \brief Initialise la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contient les arguments passés en paramètres
 * \return void
 */

int check_param(int ac, char **av, param_t *param)
{
    char optstring[]="p:x:y:n:c:f:";
    int c;

    while ((c = getopt(ac, av, optstring)) != EOF) {
        reinit_param(c, param);
    }
    if (param->clientNB == 0 || param->height == 0 || param->width == 0 ||
    param->port == 0) {
        return (-1);
    }
    return (0);
}

/**
 * \fn void check_param_n(int ac, char **av, param_t *param);
 * \brief Trouve element name de la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return int
 */

int check_param_n(int ac, char **av, param_t *param)
{
    int found_n = -1;
    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-n") == 0) {
            init_param_n(ac, av, param, i);
            i = ac;
            found_n = 1;
        }
    }
    return (found_n);
}