/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client_tools
*/

#include "server.h"

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
    SLIST_INSERT_HEAD(&server->clients, new, next);
    return (SUCCESS);
}

bool rm_client(server_t *server, client_t *client)
{
    SLIST_REMOVE(&server->clients, client, client_s, next);
    close(client->sck.fd);
    free(client);
    return (SUCCESS);
}

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