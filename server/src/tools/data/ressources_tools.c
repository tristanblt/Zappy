/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** ressource_tool
*/

#include "server.h"

/**
 * \fn void init_ressources(ressources_t *res)
 * \brief Fonction qui set toutes les valeurs de res à 0
 *
 * \param res la structure à set
 * \return rien
 */
void init_ressources(ressources_t *res)
{
    res->food = 0;
    res->deraumere = 0;
    res->linemate = 0;
    res->mendiane = 0;
    res->phiras = 0;
    res->sibur = 0;
    res->thystame = 0;
}

int get_ressource_number(char *ressource)
{
    if (!strcmp(ressource, "food"))
        return(0);
    if (!strcmp(ressource, "linemate"))
        return(1);
    if (!strcmp(ressource, "deraumere"))
        return(2);
    if (!strcmp(ressource, "sibur"))
        return(3);
    if (!strcmp(ressource, "mendiane"))
        return(4);
    if (!strcmp(ressource, "phiras"))
        return(5);
    if (!strcmp(ressource, "thystame"))
        return(6);
    return (-1);
}