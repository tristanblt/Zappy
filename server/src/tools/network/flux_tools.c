/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** flux_tools
*/

#include "server.h"


/**
 * \fn bool read_flux(server_t *server, client_t *client)
 * \brief Fonction qui va lire la socket client
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \return true en succès et false en cas d'erreur
 */

bool read_flux(server_t *server, client_t *client)
{
    char tmp[BUFF_SIZE] = {0};
    int rd = read(client->sck.fd, tmp,
    BUFF_SIZE - client->in.nb);
    // printf("------ read flux-> %s\n", tmp);
    if (rd == -1)
        return (ERROR);
    if (rd == 0) {
        rm_client(server, client);
        return (ERROR);
    }
    add_raw_data(&client->in, tmp);
    return (SUCCESS);
}

/**
 * \fn bool write_flux(server_t *server, client_t *client)
 * \brief Fonction qui va écrire sur la socket client
 *
 * \param server la variable principale du projet
 * \param client client actuel
 * \return true en succès et false en cas d'erreur
 */

bool write_flux(client_t *client)
{
    int wr = write(client->sck.fd, client->out.buff, client->out.nb);
    // printf("------ write flux-> %s\n", client->out.buff);
    if (wr == -1)
        return (ERROR);
    remove_data(&client->out, wr);
    return (SUCCESS);
}

/**
 * \fn void add_data(flux_t *flux, int n, ...)
 * \brief Fonction qui va remplir le flux avec un nombre de char * non défini,
 * met un "\r\n" à la fin
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