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
bool take_obj3(server_t *server, client_t *c, char *arg,
extracted_content_t content)
{
    if (strcmp("mendiane", arg) == 0 && content.ressources->mendiane > 0) {
        ((c_data_t *)c->data)->inventory.mendiane += 1;
        content.ressources->mendiane -= 1;
        pgt(server, c, "mendiane");
        return (true);
    }
    if (strcmp("phiras", arg) == 0 && content.ressources->phiras > 0) {
        ((c_data_t *)c->data)->inventory.phiras += 1;
        content.ressources->phiras -= 1;
        pgt(server, c, "phiras");
        return (true);
    }
    if (strcmp("thystame", arg) == 0 && content.ressources->thystame > 0) {
        ((c_data_t *)c->data)->inventory.thystame += 1;
        content.ressources->thystame -= 1;
        pgt(server, c, "thystame");
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
bool take_obj2(server_t *server, client_t *c, char *arg,
extracted_content_t content)
{
    if (strcmp("deraumere", arg) == 0 && content.ressources->deraumere > 0) {
        ((c_data_t *)c->data)->inventory.deraumere += 1;
        content.ressources->deraumere -= 1;
        pgt(server, c, "deraumere");
        return (true);
    }
    if (strcmp("sibur", arg) == 0 && content.ressources->sibur > 0) {
        ((c_data_t *)c->data)->inventory.sibur += 1;
        content.ressources->sibur -= 1;
        pgt(server, c, "sibur");
        return (true);
    }
    if (take_obj3(server, c, arg, content) == true)
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
bool take_obj(server_t *server, client_t *c, char *arg,
extracted_content_t content)
{
    if (strcmp("food", arg) == 0 && content.ressources->food > 0) {
        ((c_data_t *)c->data)->inventory.food += 126.0 / server->t.ratio;
        content.ressources->food -= 1;
        pgt(server, c, "food");
        return (true);
    }
    if (strcmp("linemate", arg) == 0 && content.ressources->linemate > 0) {
        ((c_data_t *)c->data)->inventory.linemate += 1;
        content.ressources->linemate -= 1;
        pgt(server, c, "linemate");
        return (true);
    }
    if (take_obj2(server, c, arg, content) == true)
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

    content = get_tile_content(&z->data, z->server, x, y);
    if (take_obj(z->server, c, arg, content) == true) {
        add_data(&c->out, 1, "ok");
        return (SUCCESS);
    } else {
        add_data(&c->out, 1, "ko");
        return (SUCCESS);
    }
    return (SUCCESS);
}

bool start_take_cmd(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}