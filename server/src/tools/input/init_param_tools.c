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
    param->freq = 100;
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
    case 'f':
        param->freq = atoi(optarg);
        break;
    }
}

/**
 * \fn int add_n(char **av, param_t *param, int i, int nbName);
 * \brief Initialise le/les element(s) name de la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \param i position du "-n"
 * \param nbName indice du nombre de name
 * \return int
 */
int add_n(char **av, param_t *param, int i, int nbName)
{
    if (strchr(av[i], ' ') == NULL) {
        param->name = realloc(param->name, sizeof(char *) * (nbName + 2));
        if (param->name == NULL)
            return (-1);
        param->name[nbName] = malloc(sizeof(char) * strlen(av[i]) + 1);
        strcpy(param->name[nbName], av[i]);
        param->name[nbName + 1] = NULL;
    } else {
        return (-1);
    }
    return (0);
}

/**
 * \fn int init_param_n(int ac, char **av, param_t *param, int i);
 * \brief Trouve les param name pour les initailiser
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \param i position du "-n"
 * \return int
 */
int init_param_n(int ac, char **av, param_t *param, int i)
{
    i++;
    int nbName = 0;

    while (i < ac && strncmp(av[i], "-", 1) != 0) {
        if (add_n(av, param, i, nbName) == -1)
            return (-1);
        i++;
        nbName++;
    }
    if (param->name == NULL) {
        display_usage_s();
    }
    return (0);
}