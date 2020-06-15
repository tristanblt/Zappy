/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take
*/

#include "server.h"

/**
 * \fn int take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 0 = succes
 */
int take(zappy_data_t *z, client_t *c, char *arg)
{
    extracted_content_t content;
    int y = ((c_data_t *)c->data)->pos.y;
    int x = ((c_data_t *)c->data)->pos.x;

    content = get_tile_content(((c_data_t *)c->data), z->server, x, y);
    ((c_data_t *)c->data)->inventory.food += content.ressources->food;
    ((c_data_t *)c->data)->inventory.linemate += content.ressources->linemate;
    ((c_data_t *)c->data)->inventory.deraumere += \
    content.ressources->deraumere;
    ((c_data_t *)c->data)->inventory.sibur += content.ressources->sibur;
    ((c_data_t *)c->data)->inventory.mendiane += content.ressources->mendiane;
    ((c_data_t *)c->data)->inventory.phiras += content.ressources->phiras;
    ((c_data_t *)c->data)->inventory.thystame += content.ressources->thystame;
    content.ressources->food = 0;
    content.ressources->linemate = 0;
    content.ressources->deraumere = 0;
    content.ressources->sibur = 0;
    content.ressources->mendiane = 0;
    content.ressources->phiras = 0;
    content.ressources->thystame = 0;
}