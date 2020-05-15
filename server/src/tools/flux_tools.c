/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** flux_tools
*/

#include "server.h"


/**
 * \fn bool read_flux(server_t *server, int idx)
 * \brief Fonction qui va lire la socket client
 *
 * \param server la variable principale du projet
 * \param idx index du client
 * \return true en succès et false en cas d'erreur
 */

bool read_flux(server_t *server, int idx)
{
    char tmp[BUFF_SIZE] = {0};
    int rd = read(server->clients.c[idx].sck.fd, tmp,
    BUFF_SIZE - server->clients.c[idx].in.nb);

    if (rd == 0) {
        rm_client(server, idx);
        return (SUCCESS);
    }
    add_raw_data(&server->clients.c[idx].in, tmp);
    return (SUCCESS);
}


/**
 * \fn bool write_flux(server_t *server, int idx)
 * \brief Fonction qui va écrire sur la socket client
 *
 * \param server la variable principale du projet
 * \param idx index du client
 * \return true en succès et false en cas d'erreur
 */

bool write_flux(server_t *server, int idx)
{
    int wr = write(server->clients.c[idx].sck.fd,
    server->clients.c[idx].out.buff, server->clients.c[idx].out.nb);

    remove_data(&server->clients.c[idx].out, wr);
    return (SUCCESS);
}


/**
 * \fn void add_data(flux_t *flux, int n, ...)
 * \brief Fonction qui va remplir le flux avec un nombre de char * non défini, met un "\r\n" à la fin
 *
 * \param flux la fluxque l'on veut remplir
 * \param n le nombre de char * pour la va_list
 * \return rien
 */

void add_data(flux_t *flux, int n, ...)
{
    va_list args;
    char *temp;

    va_start(args, n);
    for (int i = 0; i < n; i++) {
        temp = va_arg(args, char *);
        if (strlen(temp) + flux->nb + 2 + ((i != n - 1) ? 1 : 0) > BUFF_SIZE) {
            remove_data(flux, flux->nb);
            return;
        }
        strncpy(flux->buff + flux->nb, temp, strlen(temp));
        flux->nb += strlen(temp);
        if (i != n - 1) {
            strcat(flux->buff, " ");
            flux->nb++;
        }
    }
    strcpy(flux->buff + flux->nb, "\r\n");
    flux->nb += 2;
    va_end(args);
}


/**
 * \fn void add_data(flux_t *flux, int n, ...)
 * \brief Fonction qui va remplir le flux avec un char *
 *
 * \param flux la fluxque l'on veut remplir
 * \param str la donnée à ajouter
 * \return rien
 */

void add_raw_data(flux_t *flux, char *str)
{
    if (strlen(str) + flux->nb > BUFF_SIZE)
        remove_data(flux, flux->nb);
    strncpy(flux->buff + flux->nb, str, strlen(str));
    flux->nb += strlen(str);
}


/**
 * \fn void remove_data(flux_t *flux, int size)
 * \brief Fonction qui va vider le flux de size donnée
 *
 * \param flux la fluxque l'on veut remplir
 * \param size taille de la donnée que l'on veut retirer
 * \return rien
 */

void remove_data(flux_t *flux, int size)
{
    if (size < BUFF_SIZE) {
        memmove(flux->buff, flux->buff + size, size);
        flux->nb -= size;
        flux->buff[flux->nb] = 0;
        memset(flux->buff + flux->nb, 0, BUFF_SIZE - flux->nb);
    } else {
        flux->nb = 0;
        flux->buff[flux->nb] = 0;
        memset(flux->buff, 0, BUFF_SIZE);
    }
}