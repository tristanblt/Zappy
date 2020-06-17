/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** data_tools
*/

#include "server.h"

/**
 * \fn c_data_t *init_client_data(void)
 * \brief Fonction qui permet d'initialiser c_data de client
 *
 * \return c_data * initialisée sauf pour ce qui est de la team et de la
 * position
 */

c_data_t *init_client_data(int f)
{
    c_data_t *new = malloc(sizeof(c_data_t));
    static int idx = 0;

    if (!new)
        return (NULL);
    new->team = NULL;
    new->dir = rand() % 4;
    new->cool_down = 0;
    new->level = 1;
    new->pos.x = 0;
    new->pos.y = 0;
    new->is_alive = true;
    new->req_cntx = END;
    new->team = NULL;
    new->idx = idx;
    init_ressources(&new->inventory);
    new->inventory.food = 1260.0 / f;
    idx++;
    return (new);
}

/**
 * \fn map_node_t *init_tile(int x, int y)
 * \brief Fonction qui permet d'initialiser la data du server
 *
 * \param data à initialiser
 * \param param pour initialiser correctement data
 * \return true en succes et error en echec
 */
bool init_server_data(s_data_t *data, param_t params)
{
    int nb = 0;

    data->f = params.freq;
    data->map_sz.y = params.height;
    data->map_sz.x = params.width;
    data->nb_mates = params.clientNB;
    data->spawn_cd = 0;
    SLIST_INIT(&data->eggs);
    for (nb = 0; params.name[nb]; nb++);
    if ((data->teams = malloc(sizeof(team_t) * nb)) == NULL)
        return (ERROR);
    for (int i = 0; i < nb; i++) {
        data->teams[i].name = params.name[i];
        data->teams[i].nb = 0;
    }
    data->nb_teams = nb;
    if (!(data->map = create_map((position_t){params.width, params.height}))) {
        free(data->teams);
        return (ERROR);
    }
    map_node_t *tmp = data->map;
    printf("x = %i, y = %i\n", tmp->coordinates.x, tmp->coordinates.x);
    printf("%p\n", tmp);
    tmp = tmp->right;
    printf("x = %i, y = %i\n", tmp->coordinates.x, tmp->coordinates.x);
    printf("%p\n", tmp);
    return (SUCCESS);
}

/**
 * \fn void free_server_data(s_data_t *data)
 * \brief Fonction qui permet de free data_s
 *
 * \param data la data à free
 * \return rien
 */
void free_server_data(s_data_t *data)
{
    egg_t *tmp;

    while (!SLIST_EMPTY(&data->eggs)) {
        tmp = SLIST_FIRST(&data->eggs);
        SLIST_REMOVE_HEAD(&data->eggs, next);
        free(tmp);
    }
    for (int i = 0; i < data->nb_teams; i++)
        free(data->teams[i].name);
    free_map(data->map, (position_t){data->map_sz.x, data->map_sz.y});
    free(data->teams);
}