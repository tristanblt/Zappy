/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client_tools
*/

#include "server.h"

bool add_client(server_t *server)
{
    server->clients.nb++;
    server->clients.c = realloc(server->clients.c,
    server->clients.nb * sizeof(client_t));
    if (server->clients.c == NULL ||
    init_client(server, server->clients.nb - 1) == ERROR) {
        end_server(server);
        return (ERROR);
    }
    return (SUCCESS);
}

bool rm_client(server_t *server, int index)
{
    client_t *new_c = NULL;
    int pos = 0;

    if (server->clients.nb > 1 &&
    (new_c = malloc(sizeof(client_t) * (server->clients.nb - 1))) == NULL) {
        end_server(server);
        return (ERROR);
    }
    for (int i = 0; i < server->clients.nb; i++) {
        if (i != index) {
            new_c[pos] = server->clients.c[i];
            pos++;
        }
    }
    close(server->clients.c[index].sck.fd);
    if (server->clients.nb > 1) {
        free(server->clients.c);
        server->clients.c = new_c;
    }
    server->clients.nb--;
    return (SUCCESS);
}

bool init_client(server_t *s, int idx)
{
    socklen_t sz = sizeof(s->clients.c[idx].sck.add);

    s->clients.c[idx].sck.fd =
    accept(s->sck.fd, (struct sockaddr *)&s->clients.c[idx].sck.add, &sz);
    if (s->clients.c[idx].sck.fd == -1)
        return (ERROR);
    s->clients.c[idx].in.nb = 0;
    memset(s->clients.c[idx].in.buff, 0, BUFF_SIZE);
    s->clients.c[idx].out.nb = 0;
    memset(s->clients.c[idx].out.buff, 0, BUFF_SIZE);
    return (SUCCESS);
}