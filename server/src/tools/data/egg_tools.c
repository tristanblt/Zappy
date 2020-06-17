/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** egg_tools
*/

#include "server.h"

/**
 * \fn bool add_egg(zappy_data_t *z, char *team, position_t pos)
 * \brief Fonction qui malloc, init et ajoute un oeuf à la liste
 *
 * \param z la structure preincipale du programme
 * \param team le nom de la team de l'oeuf
 * \param pos sa position sur la map
 * \return true en succes et false en erreur
 */
bool add_egg(zappy_data_t *z, char *team, position_t pos)
{
    egg_t *new = malloc(sizeof(egg_t));
    static int idx = 0;

    if (new == NULL)
        return (ERROR);
    new->pos.x = pos.x;
    new->pos.y = pos.y;
    new->status = 600.0 / z->data.f;
    new->team = team;
    new->idx = idx;
    idx++;
    SLIST_INSERT_HEAD(&z->data.eggs, new, next);
    return (SUCCESS);
}

/**
 * \fn egg_t *get_egg_by_team(zappy_data_t *z, char *team)
 * \brief Fonction qui récupère un oeuf eclot de la team donnée
 *
 * \param z structure principale du programme
 * \param y team nom de la team
 * \return un oeuf de la team eclot sinon NULL
 */
egg_t *get_egg_by_team(zappy_data_t *z, char *team)
{
    egg_t *tmp;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        if (!strcmp(tmp->team, team) && tmp->status == HATCHED)
            return (tmp);
    }
    return (NULL);
}

/**
 * \fn void assign_egg_to_client(zappy_data_t *z, client_t *client, egg_t *egg)
 * \brief Fonction qui assigne la pos et la team à un client avant de le
 * supprimer
 *
 * \param z structure principale du projet
 * \param client le client auquel on assigne la data
 * \param egg l'oeuf qui sera supprimé après avoir donné sa data
 * \return rien
 */
void assign_egg_to_client(zappy_data_t *z, client_t *client, egg_t *egg)
{
    ((c_data_t *)client->data)->pos.x = egg->pos.x;
    ((c_data_t *)client->data)->pos.y = egg->pos.y;
    ((c_data_t *)client->data)->team = egg->team;
    SLIST_REMOVE(&z->data.eggs, egg, egg_s, next);
    free(egg);
}

/**
 * \fn bool init_client_context(zappy_data_t *z, client_t *client, char *name)
 * \brief Fonction qui assigne des coordonnées et une team au client si
 * possible, sinon il est déconecté
 *
 * \param z structure principale du programme
 * \param client le client a setup
 * \param name le nom de la team
 * \return une nouvelle tile
 */
bool init_client_context(zappy_data_t *z, client_t *client, char *name)
{
    egg_t *egg = get_egg_by_team(z, name);
    team_t *team = get_team_by_name(z->data.teams, z->data.nb_teams, name);

    if (!team) {
        rm_client(z->server, client);
        return (ERROR);
    }
    if (team->nb == 0) {
        ((c_data_t *)client->data)->pos.x = rand() % z->data.map_sz.x;
        ((c_data_t *)client->data)->pos.y = rand() % z->data.map_sz.y;
        ((c_data_t *)client->data)->team = name;
    } else if (team->nb < z->data.nb_mates && egg)
        assign_egg_to_client(z, client, egg);
    else {
        rm_client(z->server, client);
        return (ERROR);
    }
    team->nb++;
    return (SUCCESS);
}

/**
 * \fn void update_egg_status(zappy_data_t *z)
 * \brief Fonction qui update le status des oeufs
 *
 * \param z structure principale du programme
 * \return rien
 */
void update_egg_status(zappy_data_t *z)
{
    egg_t *tmp;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        if (tmp->status - z->server->t.delta_time > 0)
            tmp->status -= z->server->t.delta_time;
        else if (tmp->status != HATCHED) {
            tmp->status = HATCHED;
        }
    }
}