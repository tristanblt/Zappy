/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** command_tools
*/

#include "server.h"

#define NB_CMDS 0

const command_t cmds[NB_CMDS] = {};


/**
 * \fn bool switch_command(server_t *server, int client, char *command)
 * \brief Fonction qui va appeller la fct corespondant à la commande trouvée
 *
 * \param server la variable principale du projet
 * \param client index du client
 * \param command corps de la commande
 * \return true en succès et false en cas d'erreur
 */

bool switch_command(server_t *server, int client, char *command)
{
    char code[4] = {0};

    memcpy(code, command, 3);
    for (int i = 0; i < NB_CMDS; i++)
        if (!strncmp(cmds[i].token, command, cmds[i].token_len))
            return (cmds[i].fct(server, client, command + cmds[i].token_len));
    return (SUCCESS);
}


/**
 * \fn bool search_command_in_client(server_t *server, int client)
 * \brief Fonction qui va appeller switch_commands pour chaque commandes dans le flux in
 *
 * \param server la variable principale du projet
 * \param client index du client
 * \return true en succès et false en cas d'erreur
 */

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
            return (ERROR);
        remove_data(&server->clients.c[client].in, size_cmd);
    }
    return (SUCCESS);
}


/**
 * \fn bool handle_commands(server_t *server)
 * \brief Fonction qui appelle la gestion de commandes pour chaque client
 *
 * \param server la variable principale du projet
 * \return true en succès et false en cas d'erreur
 */

bool handle_commands(server_t *server)
{
    for (int i = 0; i < server->clients.nb; i++)
        if (!search_command_in_client(server, i))
            return (ERROR);
    return (SUCCESS);
}