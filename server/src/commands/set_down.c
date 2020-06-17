/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** set_down
*/

#include "server.h"

/**
 * \fn bool set_obj4(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par set_obj3
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */

bool set_obj4(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("phiras", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.phiras > 0) {
        content.ressources->phiras += 1;
        ((c_data_t *)c->data)->inventory.phiras -= 1;
        return (1);
    }
    if (strcmp("thystame", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.thystame > 0) {
        content.ressources->thystame += 1;
        ((c_data_t *)c->data)->inventory.thystame -= 1;
        return (1);
    } else {
        return (0);
    }
}

/**
 * \fn bool set_obj3(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par set_obj2
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool set_obj3(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("deraumere", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.deraumere > 0) {
        content.ressources->deraumere += 1;
        ((c_data_t *)c->data)->inventory.deraumere -= 1;
        return (1);
    }
    if (set_obj4(c, arg, content) == true)
        return (1);
    else
        return (0);
}

/**
 * \fn bool set_obj2(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par set_obj
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool set_obj2(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("sibur", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.sibur > 0) {
        content.ressources->sibur += 1;
        ((c_data_t *)c->data)->inventory.sibur -= 1;
        return (1);
    }
    if (strcmp("mendiane", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.mendiane > 0) {
        content.ressources->mendiane += 1;
        ((c_data_t *)c->data)->inventory.mendiane -= 1;
        return (1);
    }
    if (set_obj3(c, arg, content) == true)
        return (1);
    else
        return (0);
}

/**
 * \fn bool set_obj(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par set
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool set_obj(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("food", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.food > 0) {
        content.ressources->food += 126;
        ((c_data_t *)c->data)->inventory.food -= 126;
        return (1);
    }
    if (strcmp("linemate", arg) == 0 &&
    ((c_data_t *)c->data)->inventory.linemate > 0) {
        content.ressources->linemate += 1;
        ((c_data_t *)c->data)->inventory.linemate -= 1;
        return (1);
    }
    if (set_obj2(c, arg, content) == true)
        return (1);
    else
        return (0);
}

/**
 * \fn bool take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return succes ou error
 */
bool end_set_cmd(zappy_data_t *z, client_t *c, char *arg)
{
    extracted_content_t content;
    int y = ((c_data_t *)c->data)->pos.y;
    int x = ((c_data_t *)c->data)->pos.x;

    printf("ok2\n");
    content = get_tile_content(&z->data, z->server, x, y);
    if (set_obj(c, arg, content) == true) {
        printf("end = ok\n");
        add_data(&c->out, 1, "ok");
        return (SUCCESS);
    } else {
        printf("end = ko\n");
        add_data(&c->out, 1, "ko");
        return (ERROR);
    }
}
