/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn void init_param(param_t *param)
 * \brief Init param_t structure
 *
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return void
 */

void init_param(param_t *param)
{
    param->port = NULL;
    param->width = 0;
    param->height = 0;
    param->name = NULL;
    param->clientNB = 0;
    param->freq = 0;
}

/**
 * \fn void reinit_param(int c, param_t *param);
 * \brief Reinitialise la structure param_t
 *
 * \param c param en question (p,x,y,...)
 * \param param_t structure qui contient les arguments passés en paramètres
 * \return void
 */

void reinit_param(int c, param_t *param)
{
    switch (c) {
    case 'p':
        param->port = malloc(sizeof(char) * strlen(optarg) + 1);
        strcpy(param->port, optarg);
        break;
    case 'x':
        param->width = atoi(optarg);
        break;
    case 'y':
        param->height = atoi(optarg);
        break;
    case 'c':
        param->clientNB = atoi(optarg);
        break;
    case 'f':
        param->freq = atoi(optarg);
        break;
    }
}

/**
 * \fn int init_param_n(int ac, char **av, param_t *param, int i);
 * \brief Initialise le/les element(s) name de la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \param i position du "-n"
 * \return int
 */

int init_param_n(int ac, char **av, param_t *param, int i)
{
    int nbName = 0;
    i++;

    while (i < ac && strncmp(av[i], "-", 1) != 0) {
        param->name = realloc(param->name, sizeof(char *) * (nbName + 2));
        if (param->name == NULL)
            return (ERROR);
        param->name[nbName] = malloc(sizeof(char) * strlen(av[i]) + 1);
        strcpy(param->name[nbName], av[i]);
        nbName++;
        param->name[nbName] = NULL;
        i++;
    }
    if (param->name == NULL) {
        display_usage_s();
    }
    return (SUCCESS);
}