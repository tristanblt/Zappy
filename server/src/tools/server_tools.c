/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server_tools
*/

#include "server.h"

server_t *init_server(char *port)
{
    server_t *new = calloc(1, sizeof(server_t));

    if (new == NULL)
        return (NULL);
    new->clients.nb = 0;
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

void end_server(server_t *server)
{
    close(server->sck.fd);
    for (int i = 0; i < server->clients.nb; i++)
        close(server->clients.c[i].sck.fd);
    free(server->clients.c);
    free(server);
}

void update_fds(server_t *server)
{
    FD_ZERO(&server->fds.read);
    FD_ZERO(&server->fds.write);
    FD_ZERO(&server->fds.error);
    for (int i = 0; i < server->clients.nb; i++) {
        FD_SET(server->clients.c[i].sck.fd, &server->fds.read);
        if (server->clients.c[i].out.nb > 0)
            FD_SET(server->clients.c[i].sck.fd, &server->fds.write);
        FD_SET(server->clients.c[i].sck.fd, &server->fds.error);
    }
    FD_SET(server->sck.fd, &server->fds.read);
    FD_SET(server->sck.fd, &server->fds.error);
}

bool handle_fds(server_t *server)
{
    bool is_ok = SUCCESS;

    for (int i = 0; i < server->clients.nb && is_ok != ERROR; i++) {
        if (FD_ISSET(server->clients.c[i].sck.fd, &server->fds.read) && is_ok)
            is_ok = read_flux(server, i);
        if (FD_ISSET(server->clients.c[i].sck.fd, &server->fds.write) && is_ok)
            is_ok = write_flux(server, i);
        if (FD_ISSET(server->clients.c[i].sck.fd, &server->fds.error) && is_ok) {
            is_ok = rm_client(server, i);
        }
    }
    if (is_ok == ERROR || !server)
        return (ERROR);
    if (FD_ISSET(server->sck.fd, &server->fds.read) > 0)
        is_ok = add_client(server);
    if (!server || !is_ok || FD_ISSET(server->sck.fd, &server->fds.error) > 0)
        return (ERROR);
    return (is_ok);
}

bool server_iteration(server_t *server)
{
    update_fds(server);
    if (select(FD_SETSIZE, &server->fds.read, &server->fds.write,
        &server->fds.error, NULL) == -1)
        return (ERROR);
    return (handle_fds(server));
}