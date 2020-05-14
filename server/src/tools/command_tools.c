/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** command_tools
*/

#include "server.h"

#define NB_CMDS 0

const command_t cmds[NB_CMDS] = {};

bool switch_command(server_t *server, int client, char *command)
{
    char code[4] = {0};

    memcpy(code, command, 3);
    for (int i = 0; i < NB_CMDS; i++)
        if (!strcmp(cmds[i].token, code))
            cmds[i].fct(server, client, command + 4);
    return (true);
}

bool search_command_in_client(server_t *server, int client)
{
    char *find_cmd;
    int size_cmd;

    while (true) {
        find_cmd = strstr(server->clients.c[client].in.buff, "\r\n");
        if (!find_cmd)
            break;
        size_cmd = find_cmd - server->clients.c[client].in.buff + 2;
        *find_cmd = 0;
        if (!switch_command(server, client, server->clients.c[client].in.buff))
            return (false);
        remove_data(&server->clients.c[client].in, size_cmd);
    }
    return (true);
}

bool handle_commands(server_t *server)
{
    for (int i = 0; i < server->clients.nb; i++)
        if (!search_command_in_client(server, i))
            return (false);
    return (true);
}