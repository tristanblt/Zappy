/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** look
*/

#include "server.h"

/**
 * \fn bool start_look(zappy_data_t *z, client_t *client, char *command)
 * \brief Fonction permettant de set le cool_down de la fonction look
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 0 en cas de succès
 */
bool start_look(zappy_data_t *z, client_t *client, char *command)
{
    (void)command;
    ((c_data_t *)client->data)->cool_down = 7.0 / z->data.f;
    return (SUCCESS);
}

/**
 * \fn bool end_look(server_t *server, client_t *client, char *arg)
 * \brief Fonction qui permet de retourner la vision
 *
 * \param z la variable principale du projet
 * \param client le client appelant cette fonction
 * \param arg les arguments
 * \return 0 en cas de succès
 */
bool end_look(zappy_data_t *z, client_t *client, char *arg)
{
    (void)arg;
    printf("look level: %i\n", ((c_data_t *)client->data)->level);
    switch (((c_data_t *)client->data)->dir) {
    case 1:
        look_bottom_top(client, z, -1);
        break;
    case 2:
        look_right_left(client, z, 1);
        break;
    case 3:
        look_bottom_top(client, z, 1);
        break;
    case 4:
        look_right_left(client, z, -1);
        break;
    }
    return (SUCCESS);
}