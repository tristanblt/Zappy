/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** request_tools
*/

#include "server.h"

void init_requests(request_manager_t *r)
{
    r->nb = 0;
    r->pos = 0;
    for (int i = 0; i < 10; i++)
        memset(r->bodies[i], '\0', BUFF_SIZE);
}

void add_to_requests(char *buff, client_t *client, int size)
{
    if (client->requests.nb == 10)
        return;
    for (int i = client->requests.pos + 1; i < 10; i++) {
        if (client->requests.bodies[i][0] == '\0') {
            strncpy(client->requests.bodies[i], buff, size);
            client->requests.nb++;
            return;
        }
    }
    for (int i = 0; i < client->requests.pos; i++) {
        if (client->requests.bodies[i][0] == '\0') {
            strncpy(client->requests.bodies[i], buff, size);
            client->requests.nb++;
            return;
        }
    }
}

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