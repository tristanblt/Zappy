/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client_tools
*/

#include "server.h"

/**
 * \fn client_t *get_graphical_client(server_t *server)
 * \brief Retourne le client GRAPHICAL
 *
 * \param server la variable principale du projet
 * \return le client si il y en un, sinon NULL
 */
client_t *get_graphical_client(server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            return (tmp);
    }
    return (NULL);
}

/**
 * \fn bool new_client_welcome(server_t *server, void *data)
 * \brief Ajoute un client si pas d'erreur et l'accueil
 *
 * \param server la variable principale du projet
 * \param data la data à initialiser au nouveau client
 * \return true en succès et false en cas d'erreur
 */
bool new_client_welcome(server_t *server, void *data)
{
    int is_ok = SUCCESS;
    client_t *tmp;

    if (add_client(server, data) == ERROR)
        return (ERROR);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (((c_data_t *)tmp->data)->team == NULL)
            add_data(&tmp->out, 1, "WELCOME");
    }
    return (is_ok);
}

/**
 * \fn bool add_client(server_t *server, void *data)
 * \brief Fonction qui ajoute un client à la liste du server
 *
 * \param server le server contenant les clients
 * \param data la data du client
 * \return true en success et false en error
 */
bool add_client(server_t *server, void *data)
{
    client_t *new = malloc(sizeof(client_t));

    if (new == NULL)
        return (ERROR);
    if (init_client(server, new) == ERROR) {
        free(new);
        end_server(server);
        return (ERROR);
    }
    init_requests(&new->requests);
    if (data == NULL) {
        free(new);
        return (NULL);
    }
    new->data = data;
    new->type = NOTHING;
    SLIST_INSERT_HEAD(&server->clients, new, next);
    return (SUCCESS);
}

/**
 * \fn bool rm_client(server_t *server, client_t *client)
 * \brief Fonction qui supprime un client de la liste du server
 *
 * \param server contenant les clients
 * \param client à supprimer
 * \return true en success et false en error
 */
bool rm_client(server_t *server, client_t *client)
{
    SLIST_REMOVE(&server->clients, client, client_s, next);
    close((client)->sck.fd);
    free(client);
    return (SUCCESS);
}

/**
 * \fn bool init_client(server_t *s, client_t *client)
 * \brief Fonction qui initialise un client
 *
 * \param s server contenant les clients
 * \param client à initialiser
 * \return true en success et false en error
 */
bool init_client(server_t *s, client_t *client)
{
    socklen_t sz = sizeof(client->sck.add);

    client->sck.fd =
    accept(s->sck.fd, (struct sockaddr *)&client->sck.add, &sz);
    if (client->sck.fd == -1)
        return (ERROR);
    client->in.nb = 0;
    memset(client->in.buff, 0, BUFF_SIZE);
    client->out.nb = 0;
    memset(client->out.buff, 0, BUFF_SIZE);
    return (SUCCESS);
}