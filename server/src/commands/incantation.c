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
bool is_incantation_possible(ressources_t inventory, recipe_t incantation,
int nb_player)
{
    if (nb_player < incantation.nb_player)
        return false;
    if (inventory.deraumere < incantation.needed.deraumere)
        return false;
    if (inventory.food < incantation.needed.food)
        return false;
    if (inventory.linemate < incantation.needed.linemate)
        return false;
    if (inventory.mendiane < incantation.needed.mendiane)
        return false;
    if (inventory.phiras < incantation.needed.phiras)
        return false;
    if (inventory.sibur < incantation.needed.sibur)
        return false;
    if (inventory.thystame < incantation.needed.thystame)
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
void destruction_ressources(ressources_t inventory, ressources_t incantation)
{
    inventory.deraumere -= incantation.deraumere;
    inventory.food -= incantation.food;
    inventory.linemate -= incantation.linemate;
    inventory.mendiane -= incantation.mendiane;
    inventory.phiras -= incantation.phiras;
    inventory.sibur -= incantation.sibur;
    inventory.thystame -= incantation.thystame;
}

/**
 * \fn int incantation(server_t *server, client_t *client, char *arg)
 * \brief réaliser l'incatation pour le passage de niveau
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 0 en cas de succès, 1 quand l'incantation n'est pas possible
 */
int incantation(zappy_data_t *z, client_t *client, char *arg)
{
    c_data_t *data = ((c_data_t *)client->data);
    int nb_player = player_same_level(z->server, data->pos.x, data->pos.y,
    data->level);
    char buff[2] = {0};

    if (is_incantation_possible(data->inventory, recipes[data->level - 1],
    nb_player) == false) {
        add_raw_data(&client->out, "ko\n");
        return (1);
    }
    destruction_ressources(data->inventory, recipes[data->level - 1].needed);

    add_raw_data(&client->out, "Elevation underway\n");
    add_raw_data(&client->out, "Current level:");
    sprintf(buff, "%d", data->level);
    add_raw_data(&client->out, buff);
    add_raw_data(&client->out, "\n");

    data->level += 1;
    return (0);
}