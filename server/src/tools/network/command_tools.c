/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** command_tools
*/

#include "server.h"

#define NB_CMDS 23

const command_t cmds[NB_CMDS] = {
    {"Forward", 7, &start_move_cmd, &end_move_cmd, AI},
    {"Look", 4, &start_look, &end_look, AI},
    {"Incantation", 11, &start_incantation, &end_incantation, AI},
    {"Take ", 5, &start_take_cmd, &end_take_cmd, AI},
    {"Set ", 4, &start_set_cmd, &end_set_cmd, AI},
    {"Right", 5, &start_rotate_cmd, &rotate_right_cmd, AI},
    {"Left", 4, &start_rotate_cmd, &rotate_left_cmd, AI},
    {"Inventory", 9, &start_inventory_cmd, &end_inventory_cmd, AI},
    {"Broadcast ", 10, &start_broadcast_cmd, &end_broadcast_cmd, AI},
    {"Connect_nbr", 11, &start_co_nbr_cmd, &end_co_nbr_cmd, AI},
    {"Fork", 4, &start_fork_cmd, &end_fork_cmd, AI},
    {"Eject", 5, &start_eject_cmd, &end_eject_cmd, AI},
    {"msz", 3, &start_msz, &end_msz, GRAPHICAL},
    {"bct ", 4, &start_bct, &end_bct, GRAPHICAL},
    {"mct", 3, &start_mct, &end_mct, GRAPHICAL},
    {"tna", 3, &start_tna, &end_tna, GRAPHICAL},
    {"ppo ", 4, &start_ppo, &end_ppo, GRAPHICAL},
    {"plv ", 4, &start_plv, &end_plv, GRAPHICAL},
    {"pin ", 4, &start_pin, &end_pin, GRAPHICAL},
    {"sgt", 3, &start_sgt, &end_sgt, GRAPHICAL},
    {"sst ", 4, &start_sst, &end_sst, GRAPHICAL},
    {"lei", 3, &start_lei, &end_lei, GRAPHICAL},
    {"lpi", 3, &start_lpi, &end_lpi, GRAPHICAL}
};

bool is_acceptable(client_t *client, char *command)
{
    int found;

    for (int i = 0; i < NB_CMDS; i++) {
        if (!(found = strncmp(cmds[i].token, command, cmds[i].token_len))
        && client->type != cmds[i].client_type) {
            return (false);
        }
        if (found == 0)
            break;
    }
    return (true);
}

bool is_command_graphic(char *command)
{
    for (int i = 0; i < NB_CMDS; i++) {
        if (strncmp(cmds[i].token, command, cmds[i].token_len) == 0)
            return (true);
    }
    return (false);
}

/**
 * \fn bool switch_command(server_t *server, client_t *client, char *command)
 * \brief Fonction qui va appeller la fct corespondant à la commande trouvée
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \param command corps de la commande
 * \return true en succès et false en cas d'erreur
 */
int switch_command(zappy_data_t *z, client_t *client, char *command)
{
    int ret = SUCCESS;
    if ((ret = check_client_connexion(z, client, command)) > 0)
        return (ret);
    ret = (ret == 0) ? SUCCESS : ret;
    for (int i = 0; i < NB_CMDS; i++) {
        if (!strncmp(cmds[i].token, command, cmds[i].token_len) &&
        ((c_data_t *)client->data)->req_cntx == END) {
            ((c_data_t *)client->data)->req_cntx = START;
            return (cmds[i].start(z, client, command + cmds[i].token_len));
        } else if (!strncmp(cmds[i].token, command, cmds[i].token_len) &&
        !((c_data_t *)client->data)->cool_down) {
            ((c_data_t *)client->data)->req_cntx = END;
            printf("commande en cours: %s\n", command);
            ret = cmds[i].end(z, client, command + cmds[i].token_len);
            printf("fin ret: %i\n", ret);
        }
    }
    if (client->type == GRAPHICAL && is_command_graphic(command) == false)
        suc(client);
    if (ret == SUCCESS && ((c_data_t *)client->data)->cool_down == 0)
        rm_from_request(client);
    return (ret);
}

/**
 * \fn bool search_command_in_client(server_t *server, client_t *client)
 * \brief Fonction qui va ajouter les commandes présentes dans le buffer
 * in dans requests du server
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \return rien
 */
void search_command_in_client(client_t *client)
{
    char *find_cmd;
    int size_cmd;

    while (true) {
        find_cmd = strstr(client->in.buff, "\r\n");
        if (!find_cmd)
            break;
        size_cmd = find_cmd - client->in.buff + 2;
        *find_cmd = 0;
        if (is_acceptable(client, client->in.buff)) {
            add_to_requests(client->in.buff, client, size_cmd - 2);
        }
        remove_data(&client->in, size_cmd);
    }
}

/**
 * \fn bool handle_commands(server_t *server)
 * \brief Fonction qui appelle la gestion de commandes pour chaque client
 *
 * \param server la variable principale du projet
 * \return true en succès et false en cas d'erreur
 */
bool handle_commands(zappy_data_t *z)
{
    client_t *tmp;
    client_t *tmp2;
    int s_ret;

    for (tmp = z->server->clients.slh_first; tmp != NULL;
    tmp = (tmp) ? tmp->next.sle_next : tmp2) {
        tmp2 = tmp->next.sle_next;
        search_command_in_client(tmp);
        if ((s_ret = handle_life(z, tmp)) && tmp->requests.nb && !(s_ret =
        switch_command(z, tmp, tmp->requests.bodies[tmp->requests.pos]))) {
            return (ERROR);
        }
        if (s_ret == SUPP_IN_SWITCH || s_ret == SUPP_IN_LIFE) {
            tmp = NULL;
        }
    }
    update_egg_status(z);
    return (SUCCESS);
}