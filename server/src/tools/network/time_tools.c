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
    gettimeofday(&t->last_time, NULL);
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
    struct timeval tv;

    gettimeofday(&tv, NULL);
    t->delta_time = (float)(tv.tv_usec - t->last_time.tv_usec) / 1000000 +
    (tv.tv_sec - t->last_time.tv_sec);
    t->last_time.tv_sec = tv.tv_sec;
    t->last_time.tv_usec = tv.tv_usec;
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
        else if (((c_data_t *)tmp->data)->cool_down != 0)
            ((c_data_t *)tmp->data)->cool_down = 0;
        if (((c_data_t *)tmp->data)->team &&
        ((c_data_t *)tmp->data)->inventory.food - server->t.delta_time > 0) {
            ((c_data_t *)tmp->data)->inventory.food -= server->t.delta_time;
        } else if (((c_data_t *)tmp->data)->team)
            ((c_data_t *)tmp->data)->inventory.food = 0;
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
    bool graphical_cmd = false;
    c_data_t *d;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        d = ((c_data_t *)tmp->data);
        if (tmp->type == AI && (cd == -1 || cd > d->cool_down) && d->cool_down)
            cd = d->cool_down;
        if (tmp->type == AI && (cd == -1 || cd > d->inventory.food) &&
        d->team) {
            cd = d->inventory.food;
        }
        if (tmp->type == GRAPHICAL && d->req_cntx == START)
            graphical_cmd = true;
    }
    server->t.is_needed = (cd > 0 || graphical_cmd) ? true : false;
    server->t.timeout.tv_sec = (graphical_cmd)? 0 : (long)cd;
    server->t.timeout.tv_usec = (graphical_cmd) ? 0 : 1000000 * (cd - (int)cd);
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
}