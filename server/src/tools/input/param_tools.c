/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn int game_param(int ac, char **av, param_t *param)
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
        return (-1);
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
        if (check_team_name(param) == -1) {
            display_usage_s();
            return (-1);
        }
    }
    return (0);
}

/**
 * \fn int check_team_name(param_t *param);
 * \brief Check si chaque team a un nom different
 *
 * \param param_t structure qui contient les arguments passés en paramètres
 * \return int
 */
int check_team_name(param_t *param)
{
    for (int i = 0; param->name[i + 1] != NULL; i++) {
        if (check_team_compare(param, i))
            return (-1);
    }
    return (0);
}

/**
 * \fn int check_param(int ac, char **av, param_t *param);
 * \brief Check si chaque paramettre est bien passé en ligne
 *        de commande et le reinitialise si besoin
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
        switch (c) {
        case 'c':
            param->clientNB = atoi(optarg);
            break;
        }
        reinit_param(c, param);
    }
    if (param->clientNB == 0 || param->height == 0 || param->width == 0 ||
    param->port == 0 || param->freq == -1) {
        return (-1);
    }
    return (0);
}

/**
 * \fn int check_param_n(int ac, char **av, param_t *param);
 * \brief Trouve element -n (name) de la structure param_t
 *
 * \param ac : nombre d'arguments
 * \param av : arguments entrés en execution du programme
 * \param param_t : structure qui contien les arguments passé en paramètres
 * \return int
 */
int check_param_n(int ac, char **av, param_t *param)
{
    int found_n = -1;
    int is_init = -1;

    for (int i = 0; i < ac; i++) {
        if (strcmp(av[i], "-n") == 0) {
            is_init = init_param_n(ac, av, param, i);
            i = ac;
            found_n = 1;
        }
    }
    if (is_init == -1)
        found_n = -1;
    return (found_n);
}

/**
 * \fn void free_param(param_t *param);
 * \brief Free structure param_t
 *
 * \param param_t structure qui contient les arguments passé en paramètres
 * \return void
 */
void free_param(param_t param)
{
    if (param.port != NULL)
        free(param.port);
}