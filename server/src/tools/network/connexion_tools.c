/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** connexion_tools
*/

#include "server.h"

/**
 * \fn int is_ai_client_connexion(zappy_data_t *z, client_t *client, char *command)
 * \brief Connecte un client de type ai
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \param command corps de la commande
 * \return true en succès et false en cas d'erreur
 */
int is_ai_client_connexion(zappy_data_t *z, client_t *client, char *command)
{
    char **array = split_command(command);
    char buffer[12] = {0};
    team_t *team;

    if (array == NULL)
        return (ERROR);
    if (init_client_context(z, client, array[0]) == ERROR)
        return (ERROR);
    team = get_team_by_name(z->data.teams, z->data.nb_teams,
    ((c_data_t *)client->data)->team);
    if (!team)
        return (ERROR);
    sprintf(buffer, "%d", z->data.nb_mates - team->nb);
    add_data(&client->out, 1, buffer);
    sprintf(buffer, "%d %d", ((c_data_t *)client->data)->pos.x,
    ((c_data_t *)client->data)->pos.y);
    add_data(&client->out, 1, buffer);
    client->type = AI;
    return (SUCCESS);
}

/**
 * \fn int check_client_connexion(zappy_data_t *z, client_t *client,
 * char *command)
 * \brief Vérifie si le client est connecté et si son type est donnée
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \param command corps de la commande
 * \return true en succès et false en cas d'erreur
 */
int check_client_connexion(zappy_data_t *z, client_t *client, char *command)
{
    if (((c_data_t *)client->data)->team == NULL && client->type == NOTHING) {
        if (strcmp(command, "") == 0) {
            client->type = GRAPHIQUE;
        } else if (is_ai_client_connexion(z, client, command) == ERROR)
            return (2);
        rm_from_request(client);
        return (SUCCESS);
    }
    return (0);
}