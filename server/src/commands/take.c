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
 *        Appelee par take_obj2
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 1 = succes
 */
int take_obj3(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("deraumere", arg[0]) == 0 && content.ressources->deraumere > 0) {
        ((c_data_t *)c->data)->inventory.deraumere += \
        content.ressources->deraumere;
        content.ressources->deraumere = 0;
        return (1);
    }
    if (strcmp("thystame", arg[0]) == 0 && content.ressources->thystame > 0) {
        ((c_data_t *)c->data)->inventory.thystame += \
        content.ressources->thystame;
        content.ressources->thystame = 0;
        return (1);
    } else {
        return (0);
    }
}

/**
 * \fn int take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par take_obj
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 1 = succes
 */
int take_obj2(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("sibur", arg[0]) == 0 && content.ressources->sibur > 0) {
        add_obj(c, arg, content);
        return (1);
    }
    if (strcmp("mendiane", arg[0]) == 0 && content.ressources->mendiane > 0) {
        ((c_data_t *)c->data)->inventory.mendiane += \
        content.ressources->mendiane;
        content.ressources->mendiane = 0;
        return (1);
    }
    if (strcmp("phiras", arg[0]) == 0 && content.ressources->phiras > 0) {
        ((c_data_t *)c->data)->inventory.phiras += content.ressources->phiras;
        content.ressources->phiras = 0;
        return (1);
    }
    if (take_obj3(c, arg, content) == 1)
        return (1);
    else
        return (0);
}

/**
 * \fn int take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *        Appelee par take
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 1 = succes
 */
int take_obj(client_t *c, char *arg, extracted_content_t content)
{
    if (strcmp("food", arg) == 0 && content.ressources->food > 0) {
        ((c_data_t *)c->data)->inventory.food += content.ressources->food;
        content.ressources->food = 0;
        return (1);
    }
    if (strcmp("linemate", arg) == 0 && content.ressources->linemate > 0) {
        ((c_data_t *)c->data)->inventory.linemate += \
        content.ressources->linemate;
        content.ressources->linemate = 0;
        return (1);
    }
    if (take_obj2(c, arg, content) == 1)
        return (1);
    else
        return (0);
}

/**
 * \fn int take(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de ramasser des objets
 *
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 1 = succes
 */
int take(zappy_data_t *z, client_t *c, char *arg)
{
    extracted_content_t content;
    int y = ((c_data_t *)c->data)->pos.y;
    int x = ((c_data_t *)c->data)->pos.x;

    content = get_tile_content(((c_data_t *)c->data), z->server, x, y);
    if (take_obj(c, arg, content) == 1) {
        add_data(&c->out, 1, "ok");
        return (SUCCESS);
    } else {
        add_data(&c->out, 1, "ko");
        return (ERROR);
    }
}

bool start_take_cmd(zappy_data_t *z, client_t *client, char *command)
{
    printf("ok\n");
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}