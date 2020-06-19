/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** team_tools
*/

#include "server.h"

/**
 * \fn team_t *get_team_by_name(team_t *teams, int nb, char *name)
 * \brief Fonction qui récupère une team_t par son nom
 *
 * \param teams le tableau des teams
 * \param nb le nombre de teams
 * \param name le nom de la team à trouver
 * \return une nouvelle tile
 */
team_t *get_team_by_name(team_t *teams, int nb, char *name)
{
    printf("name: %s %p\n", name, name);
    for (int i = 0; i < nb; i++)
        if (!strcmp(teams[i].name, name))
            return (&teams[i]);
    return (NULL);
}

void init_team(team_t *team, char *name)
{
    team->name = name;
    team->victory_count = 0;
    team->nb = 0;
}