/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** zappy_tools
*/

#include "server.h"

/**
 * \fn zappy_data_t *init_zappy(param_t param)
 * \brief Fonction qui malloc et init un zappy_data_t
 *
 * \param param les paramettres donnés par argv
 * \return un zappy_data_initialisé
 */
zappy_data_t *init_zappy(param_t param)
{
    zappy_data_t *new = malloc(sizeof(zappy_data_t));

    if (!new)
        return (NULL);
    if ((new->server = init_server(param.port, param.freq)) == NULL) {
        free(new);
        return (NULL);
    }
    if (init_server_data(&new->data, param) == ERROR) {
        end_server(new->server);
        free(new);
        return (NULL);
    }
    return (new);
}

/**
 * \fn void end_zappy(zappy_data_t *z, param_t param)
 * \brief Fonction qui free et termine le zappy
 *
 * \param z à free
 * \param param à free
 * \return la nouvelle valeur de la coordonée
 */
void end_zappy(zappy_data_t *z, param_t *param)
{
    end_server(z->server);
    free_server_data(&z->data);
    free(z);
    free_param(*param);
    free(param);
}