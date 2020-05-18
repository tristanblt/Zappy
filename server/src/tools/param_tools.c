/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn void check_param(int ac, char **av, param_t *param) 
 * \brief Initialise la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return void
 */

void check_param(int ac, char **av, param_t *param) 
{
    char optstring[]="p:x:y:n:c:f:";  // manque -n
    int c;
    char *name;
   
    while((c=getopt (ac, av, optstring)) != EOF)
    {
        // printf("-%c\n",(char) c);  
        switch (c) {
            case 'p':
            param->port = atoi(optarg);
            break;
            case 'x':
            param->width = atoi(optarg);
            break;
            case 'y':
            param->height = atoi(optarg);
            break;
            case 'n':
            name = optarg;
            break;
            case 'c':
            param->clientNB = atoi(optarg);
            break;
            case 'f':
            param->freq = atoi(optarg);
            break;
        }
    }
    // printf("%d\n", param->port);
    // printf("%d\n", param->width);
    // printf("%d\n", param->height);
    // printf("%s\n", name);
    // printf("%d\n", param->clientNB);
    // printf("%d\n", param->freq);
}

/**
 * \fn void init_param(int ac, char **av, param_t *param)
 * \brief Envoie vers la fonctions adaptée a/aux arguments
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return void
 */

void init_param(int ac, char **av, param_t *param)
{
    if ((ac == 2) && (strcmp(av[1], "-help") == 0)) {
        display_usage_s();
    } else {
        // printf("param_t structure has not been initialized\n");
        check_param(ac, av, param);
    }
    // param->port = 8080;
}