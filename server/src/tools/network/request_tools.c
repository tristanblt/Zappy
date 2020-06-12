/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** request_tools
*/

#include "server.h"

/**
 * \fn void init_requests(request_manager_t *r)
 * \brief Fonction qui initialise les buffeurs de request
 *
 * \param r la reuest à inittialiser
 * \return rien
 */
void init_requests(request_manager_t *r)
{
    r->nb = 0;
    r->pos = 0;
    for (int i = 0; i < 10; i++)
        memset(r->bodies[i], '\0', BUFF_SIZE);
}

/**
 * \fn void add_to_requests(char *buff, client_t *client, int size)
 * \brief Fonction qui ajoute une commande dans le buffer circulaire si il y a de la place
 *
 * \param buff la commande
 * \param client contenant requests
 * \param size la taille de la commande
 * \return rien
 */
void add_to_requests(char *buff, client_t *client, int size)
{
    if (client->requests.nb == 10)
        return;
    for (int i = client->requests.pos + 1; i < 10; i++) {
        if (client->requests.bodies[i][0] == '\0') {
            strncpy(buff, client->requests.bodies[i], size);
            client->requests.nb++;
            return;
        }
    }
    for (int i = 0; i < client->requests.pos; i++) {
        if (client->requests.bodies[i][0] == '\0') {
            strncpy(buff, client->requests.bodies[i], size);
            client->requests.nb++;
            return;
        }
    }
}

/**
 * \fn void rm_from_request(client_t *client)
 * \brief Fonction qui retire la commande en cours de traitement et bouge pos sur la prochaine
 *
 * \param client contenant requests
 * \return rien
 */
void rm_from_request(client_t *client)
{
    memset(client->requests.bodies[client->requests.pos], '\0', BUFF_SIZE);
    client->requests.nb--;
    if (client->requests.pos != 9 &&
        client->requests.bodies[client->requests.pos][0])
        client->requests.pos++;
    else
        client->requests.pos = 0;
}