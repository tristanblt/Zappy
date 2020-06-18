/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take
*/

#include "server.h"

/**
 * \fn bool take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser un objets
 *        Appelee par take_obj2
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool take_obj3(client_t *c, char *arg, extracted_content_t content)
{
    content.ressources->thystame += 1;
    if (strcmp("thystame", arg) == 0 && content.ressources->thystame > 0) {
        ((c_data_t *)c->data)->inventory.thystame += 1;
        content.ressources->thystame -= 1;
        return (true);
    } else {
        return (false);
    }
}

/**
 * \fn bool take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser un objets
 *        Appelee par take_obj
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool take_obj2(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("sibur", arg) == 0 && content.ressources->sibur > 0) {
        ((c_data_t *)c->data)->inventory.sibur += 1;
        content.ressources->sibur -= 1;
        return (true);
    }
    if (strcmp("mendiane", arg) == 0 && content.ressources->mendiane > 0) {
        ((c_data_t *)c->data)->inventory.mendiane += 1;
        content.ressources->mendiane -= 1;
        return (true);
    }
    if (strcmp("phiras", arg) == 0 && content.ressources->phiras > 0) {
        ((c_data_t *)c->data)->inventory.phiras += 1;
        content.ressources->phiras -= 1;
        return (true);
    }
    if (take_obj3(c, arg, content) == true)
        return (true);
    else
        return (false);
}

/**
 * \fn bool take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser un objets
 *        Appelee par take
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return true ou false
 */
bool take_obj(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("food", arg) == 0 && content.ressources->food > 0) {
        ((c_data_t *)c->data)->inventory.food += 126;
        content.ressources->food -= 126;
        return (true);
    }
    if (strcmp("linemate", arg) == 0 && content.ressources->linemate > 0) {
        ((c_data_t *)c->data)->inventory.linemate += 1;
        content.ressources->linemate -= 1;
        return (true);
    }
    if (strcmp("deraumere", arg) == 0 && content.ressources->deraumere > 0) {
        ((c_data_t *)c->data)->inventory.deraumere += 1;
        content.ressources->deraumere -= 1;
        return (true);
    }
    if (take_obj2(c, arg, content) == true)
        return (true);
    else
        return (false);
}

/**
 * \fn bool take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser un objets
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return succes ou error
 */
bool end_take_cmd(zappy_data_t *z, client_t *c, char *arg)
{
    extracted_content_t content;
    int y = ((c_data_t *)c->data)->pos.y;
    int x = ((c_data_t *)c->data)->pos.x;

    printf("ok2\n");
    content = get_tile_content(&z->data, z->server, x, y);
    if (take_obj(c, arg, content) == true) {
        printf("end = ok\n");
        add_data(&c->out, 1, "ok");
        return (SUCCESS);
    } else {
        printf("end = ko\n");
        add_data(&c->out, 1, "ko");
        return (ERROR);
    }
}

bool start_take_cmd(zappy_data_t *z, client_t *client, char *command)
{
    printf("ok\n");
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}