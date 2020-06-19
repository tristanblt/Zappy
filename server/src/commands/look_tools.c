/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** look_tools
*/

#include "server.h"

/**
 * \fn void print_type_content_tile(bool *first, client_t *client, int quantity,
 * char *what)
 * \brief print la ressouce le nombre de fois qu'elle existe
 *
 * \param first boolean permettant de savoir s'il s'agit de la première
 * ressource d'une tile
 * \param client le client appelant cette fonction
 * \param quantity le nombre de ressources
 * \param what une string nommant la ressource
 * \return rien
 */
void print_type_content_tile(client_t *client, int quantity,
char *what)
{
    for (int i = quantity; i > 0; i--) {
        add_raw_data(&client->out, " ");
        add_raw_data(&client->out, what);
    }
}

/**
 * \fn void print_content_tile(client_t *client, extracted_content_t content,
 * int x, int y)
 * \brief regarde toutes le ressouces et appelle la fonction pour print au
 * client
 *
 * \param client le client appelant cette fonction
 * \param content ressources de la tile
 * \param x position actuel en abscisse
 * \param y position actuel en ordonnée
 * \return rien
 */
void print_content_tile(client_t *client, extracted_content_t content, int x,
int y)
{
    if (x != ((c_data_t *)client->data)->pos.x || y
    != ((c_data_t *)client->data)->pos.y) {
        add_raw_data(&client->out, ",");
    }
    print_type_content_tile(client, content.nb_player, "player");
    print_type_content_tile(client, content.ressources->food, "food");
    print_type_content_tile(client, content.ressources->linemate,
    "linemate");
    print_type_content_tile(client, content.ressources->deraumere,
    "deraumere");
    print_type_content_tile(client, content.ressources->sibur, "sibur");
    print_type_content_tile(client, content.ressources->mendiane,
    "mendiane");
    print_type_content_tile(client, content.ressources->phiras,
    "phiras");
    print_type_content_tile(client, content.ressources->thystame,
    "thystame");
}

/**
 * \fn void look_right_left(client_t *cli, server_t *server, int signe_x)
 * \brief gère la vision vers la droite ou la gauche
 *
 * \param client le client appelant cette fonction
 * \param server la variable principale du projet
 * \param signe_x Positif pour la vision vers la droite, Négative pour la
 * vision vers la gauche
 * \return rien
 */
void look_right_left(client_t *cli, zappy_data_t *z, int signe_x)
{
    extracted_content_t content;
    int x = ((c_data_t *)cli->data)->pos.x;
    int y = ((c_data_t *)cli->data)->pos.y;

    add_raw_data(&cli->out, "[");
    for (int cpt_x = 0; cpt_x <= ((c_data_t *)cli->data)->level; cpt_x++) {
        for (int cpt_y = 0; cpt_y < 1 + cpt_x * 2; cpt_y++) {
            content = get_tile_content(&z->data, z->server, x, y);
            print_content_tile(cli, content, x, y);
            y++;
        }
        x += signe_x;
        for (int g = 0; g <= 1 + cpt_x * 2; g++)
            y--;
    }
    add_raw_data(&cli->out, " ]\r\n");
}

/**
 * \fn void look_bottom_top(client_t *cli, server_t *server, int signe_y)
 * \brief gère la vision vers le haut ou le bas
 *
 * \param client le client appelant cette fonction
 * \param server la variable principale du projet
 * \param signe_y Positif pour la vision vers le haut, Négative pour la
 * vision vers le bas
 * \return rien
 */
void look_bottom_top(client_t *cli, zappy_data_t *z, int signe_y)
{
    extracted_content_t content;
    int y = ((c_data_t *)cli->data)->pos.y;
    int x = ((c_data_t *)cli->data)->pos.x;

    add_raw_data(&cli->out, "[");
    for (int cpt_y = 0; cpt_y <= ((c_data_t *)cli->data)->level; cpt_y++) {
        for (int cpt_x = 0; cpt_x < 1 + cpt_y * 2; cpt_x++) {
            content = get_tile_content(&z->data, z->server, x, y);
            print_content_tile(cli, content, x, y);
            x++;
        }
        y += signe_y;
        for (int g = 0; g <= 1 + cpt_y * 2; g++)
            x--;
    }
    add_raw_data(&cli->out, " ]\r\n");
}
