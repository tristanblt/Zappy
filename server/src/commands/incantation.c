/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** incantation
*/

#include "server.h"

#define NB_INCANT 7

const recipe_t recipes[7] = {
    {1, {0, 1, 0, 0, 0, 0, 0}},
    {2, {0, 1, 1, 1, 0, 0, 0}},
    {2, {0, 2, 0, 1, 0, 2, 0}},
    {4, {0, 1, 1, 2, 0, 1, 0}},
    {4, {0, 1, 2, 1, 3, 0, 0}},
    {6, {0, 1, 2, 3, 0, 1, 0}},
    {6, {0, 2, 2, 2, 2, 2, 1}}
};

/**
 * \fn int player_same_level(server_t *server, int x, int y,
 * int level)
 * \brief compte le nombre de player sur la tile ayant le même niveau
 *
 * \param server la variable principale du projet
 * \param x position en abscisse de la map
 * \param y position en ordonnée de la map
 * \param level le niveau recherché
 * \return le nombre de player sur la tile ayant le même niveau
 */
int player_same_level(server_t *server, int x, int y,
int level)
{
    client_t *tmp;
    int cnt = 0;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (((c_data_t *)tmp->data)->pos.x == x &&
            ((c_data_t *)tmp->data)->pos.y == y &&
            ((c_data_t *)tmp->data)->level == level)
            cnt++;
    }
    return (cnt);
}

/**
 * \fn bool  is_incantation_possible(ressources_t inventory,
 * recipe_t incantation, int nb_player)
 * \brief vérifie si une incantation est possible
 *
 * \param inventory les ressources actuellements dans l'inventaire
 * \param incantation les ressources nécessaires à l'incantation
 * \param nb_player le nombre de player actuel du même niveau
 * \return true si l'incatation est possible, false si elle n'est pas possible
 */
bool is_incantation_possible(map_node_t *tile, recipe_t incantation,
int nb_player)
{
    if (nb_player != incantation.nb_player)
        return false;
    if (tile->ressources.deraumere != incantation.needed.deraumere)
        return false;
    if (tile->ressources.linemate != incantation.needed.linemate)
        return false;
    if (tile->ressources.mendiane != incantation.needed.mendiane)
        return false;
    if (tile->ressources.phiras != incantation.needed.phiras)
        return false;
    if (tile->ressources.sibur != incantation.needed.sibur)
        return false;
    if (tile->ressources.thystame != incantation.needed.thystame)
        return false;
    return true;
}

/**
 * \fn void destruction_ressources(ressources_t inventory,
 * ressources_t incantation)
 * \brief utilise les ressources nécessaires à l'incantation
 *
 * \param inventory les ressources actuellements dans l'inventaire
 * \param incantation les ressources nécessaires à l'incantation
 * \return rien
 */
void destruction_ressources(map_node_t *tile, ressources_t incantation)
{
    tile->ressources.deraumere -= incantation.deraumere;
    tile->ressources.food -= incantation.food;
    tile->ressources.linemate -= incantation.linemate;
    tile->ressources.mendiane -= incantation.mendiane;
    tile->ressources.phiras -= incantation.phiras;
    tile->ressources.sibur -= incantation.sibur;
    tile->ressources.thystame -= incantation.thystame;
}

/**
 * \fn bool start_incantation(zappy_data_t *z, client_t *client, char *arg)
 * \brief réaliser l'incantation pour le passage de niveau
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 1 en cas de succès, 0 quand l'incantation n'est pas possible
 */
bool start_incantation(zappy_data_t *z, client_t *client, char *arg)
{
    (void)arg;
    ((c_data_t *)client->data)->cool_down = 300.0 / z->data.f;
    add_data(&client->out, 1, "Elevation underway");
    pic(z->server, client);
    return (SUCCESS);
}

/**
 * \fn bool end_incantation(zappy_data_t *z, client_t *client, char *arg)
 * \brief terminer l'incantation pour le passage à niveau
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return SUCCESS
 */
bool end_incantation(zappy_data_t *z, client_t *client, char *arg)
{
    c_data_t *data = ((c_data_t *)client->data);
    int nb_player = player_same_level(z->server, data->pos.x, data->pos.y,
    data->level);
    map_node_t *tile = get_tile(z->data.map, data->pos.x, data->pos.y, z->data);
    (void)arg;

    if (is_incantation_possible(tile, recipes[data->level - 1],
    nb_player) == false) {
        level_up(z->server, data->pos, false);
        add_data(&client->out, 1, "ko");
        return (SUCCESS);
    }
    destruction_ressources(tile, recipes[data->level - 1].needed);
    level_up(z->server, data->pos, true);
    get_team_by_name(z->data.teams, z->data.nb_teams,
    ((c_data_t *)client->data)->team)->victory_count++;
    printf("exiting\n");
    return (SUCCESS);
}