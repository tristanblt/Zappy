/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** time_tools
*/

#include "server.h"

/**
 * \fn void init_time(time_manager_t *t, int ratio)
 * \brief Fonction qui initialise le gestionnaire de temps
 * \param t gestionnaire de temps
 * \param ratio du temps qui s'écoule
 * \return rien
 */
void init_time(time_manager_t *t, int ratio)
{
    struct timespec ts;

    timespec_get(&ts, TIME_UTC);
    t->last_time = (double)clock() / CLOCKS_PER_SEC;
    t->delta_time = 1;
    t->is_needed = false;
    t->timeout.tv_sec = 0;
    t->timeout.tv_usec = 0;
    t->ratio = ratio;
}

/**
 * \fn void update_delta_time(time_manager_t *t)
 * \brief Fonction qui calculele temp écoulé pour un itération server
 *
 * \param t time manager
 * \return rien
 */
void update_delta_time(time_manager_t *t)
{
    struct timespec ts;
    double tmp = t->last_time;

    timespec_get(&ts, TIME_UTC);
    t->last_time = (double)clock() / CLOCKS_PER_SEC;
    t->delta_time = (t->last_time - tmp);
}

/**
 * \fn void update_cool_downs(server_t *server)
 * \brief Fonction qui met à jours les cd des requettes
 *
 * \param server le server contenant les clients à update
 * \return rien
 */
void update_cool_downs(server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (((c_data_t *)tmp->data)->cool_down - server->t.delta_time > 0)
            ((c_data_t *)tmp->data)->cool_down -= server->t.delta_time;
        else if (((c_data_t *)tmp->data)->cool_down != 0) {
            rm_from_request(tmp);
            ((c_data_t *)tmp->data)->cool_down = 0;
        }
        if (((c_data_t *)tmp->data)->hunger_cd - server->t.delta_time > 0)
            ((c_data_t *)tmp->data)->hunger_cd -= server->t.delta_time;
        else {
            ((c_data_t *)tmp->data)->inventory.food--;
            ((c_data_t *)tmp->data)->hunger_cd = 126 / server->t.ratio;
        }
    }
}

/**
 * \fn void update_timeout(server_t *server)
 * \brief Fonction qui set le timeout au cooldown le plus court
 *
 * \param server
 * \return rien
 */
void update_timeout(server_t *server)
{
    client_t *tmp;
    float cd = -1;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (cd == -1 || cd > ((c_data_t *)tmp->data)->cool_down)
            cd = ((c_data_t *)tmp->data)->cool_down;
    }
    server->t.is_needed = (cd == 0) ? false : true;
    server->t.timeout.tv_sec = (long)cd;
    server->t.timeout.tv_usec = 1000 * (cd - (int)cd);
}

/**
 * \fn void handle_time(server_t *server)
 * \brief Fonction qui met à jour les cd et le delta_time
 *
 * \param server à update
 * \return rien
 */
void handle_time(server_t *server)
{
    update_delta_time(&server->t);
    update_cool_downs(server);
    update_timeout(server);
}