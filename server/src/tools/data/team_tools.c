/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** team_tools
*/

#include "server.h"

team_t *get_team_by_name(team_t *teams, int nb, char *name)
{
    for (int i = 0; i < nb; i++)
        if (!strcmp(teams[i].name, name))
            return (&teams[i]);
    return (NULL);
}