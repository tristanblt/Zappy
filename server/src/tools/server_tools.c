/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server_tools
*/

#include "server.h"

/**
 * \fn server_t *init_server(char *port)
 * \brief Fonction qui va allouer et initialiser une structure server_t
 *
 * \param port le port sur lequel ouvrir le server
 * \return la structure server_t initialisée
 */

server_t *init_server(char *port)
{
    server_t *new = calloc(1, sizeof(server_t));

    if (new == NULL)
        return (NULL);
    SLIST_INIT(&new->clients);
    new->sck.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (new->sck.fd < 0) {
        free(new);
        return (NULL);
    }
    new->running = true;
    new->sck.add.sin_addr.s_addr = INADDR_ANY;
    new->sck.add.sin_family = AF_INET;
    new->sck.add.sin_port = htons(atoi(port));
    if (bind(new->sck.fd, (struct sockaddr *)&new->sck.add,
    sizeof(new->sck.add)) == -1 || listen(new->sck.fd, 5) == -1) {
        close(new->sck.fd);
        return (NULL);
    }
    return (new);
}


/**
 * \fn void end_server(server_t *server)
 * \brief Fonction qui va free et fermer la connection
 *
 * \param server la variable principale du projet
 * \return rien
 */

void end_server(server_t *server)
{
    client_t *tmp;

    close(server->sck.fd);
    while (!SLIST_EMPTY(&server->clients))
    {
        tmp = SLIST_FIRST(&server->clients);
        SLIST_REMOVE_HEAD(&server->clients, next);
        close(tmp->sck.fd);
        free(tmp);
    }
    free(server);
}


/**
 * \fn void update_fds(server_t *server)
 * \brief Fonction qui reset les listes de fd
 *
 * \param server la variable principale du projet
 * \return rien
 */

void update_fds(server_t *server)
{
    client_t *tmp;

    FD_ZERO(&server->fds.read);
    FD_ZERO(&server->fds.write);
    FD_ZERO(&server->fds.error);
    SLIST_FOREACH(tmp, &server->clients, next) {
        FD_SET(tmp->sck.fd, &server->fds.read);
        if (tmp->out.nb > 0)
            FD_SET(tmp->sck.fd, &server->fds.write);
        FD_SET(tmp->sck.fd, &server->fds.error);
    }
    FD_SET(server->sck.fd, &server->fds.read);
    FD_SET(server->sck.fd, &server->fds.error);
}


/**
 * \fn bool handle_fds(server_t *server)
 * \brief Fonction qui parcours le clients et gère les fds
 *
 * \param server la variable principale du projet
 * \return true en cas de succès et false en cas d'erreur
 */

bool handle_fds(server_t *server)
{
    bool is_ok = SUCCESS;
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next) {
        if (is_ok == ERROR)
            break;
        if (FD_ISSET(tmp->sck.fd, &server->fds.read) && is_ok)
            is_ok = read_flux(server, tmp);
        if (FD_ISSET(tmp->sck.fd, &server->fds.write) && is_ok)
            is_ok = write_flux(server, tmp);
        if (FD_ISSET(tmp->sck.fd, &server->fds.error) && is_ok)
            is_ok = rm_client(server, tmp);
    }
    if (is_ok == ERROR || !server)
        return (ERROR);
    if (FD_ISSET(server->sck.fd, &server->fds.read) > 0)
        is_ok = add_client(server);
    if (!server || !is_ok || FD_ISSET(server->sck.fd, &server->fds.error) > 0)
        return (ERROR);
    return (is_ok);
}


/**
 * \fn bool handle_fds(server_t *server)
 * \brief Partie réseau du serveur, utilise select et gère les fds disponibles
 *
 * \param server la variable principale du projet
 * \return true en cas de succès et false en cas d'erreur
 */

bool server_iteration(server_t *server)
{
    update_fds(server);
    if (select(FD_SETSIZE, &server->fds.read, &server->fds.write,
        &server->fds.error, NULL) == -1)
        return (ERROR);
    return (handle_fds(server));
}