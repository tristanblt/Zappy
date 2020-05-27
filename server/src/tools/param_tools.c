/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

/**
 * \fn void check_param(int ac, char **av, param_t *param);
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
            // printf("-%c  ",(char) c);
            // printf("%d\n", param->port);
            break;
            case 'x':
            param->width = atoi(optarg);
            // printf("-%c  ",(char) c);
            // printf("%d\n", param->width);
            break;
            case 'y':
            param->height = atoi(optarg);
            // printf("-%c  ",(char) c);
            // printf("%d\n", param->height);
            break;
            case 'c':
            param->clientNB = atoi(optarg);
            // printf("-%c  ",(char) c);
            // printf("%d\n", param->clientNB);
            break;
            case 'f':
            param->freq = atoi(optarg);
            // printf("-%c  ",(char) c);
            // printf("%d\n", param->freq);
            break;
        }
    }
}

/**
 * \fn void init_param_n(int ac, char **av, param_t *param, int i);
 * \brief Initialise le/les element(s) name de la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \param i position du "-n"
 * \return void
 */

void init_param_n(int ac, char **av, param_t *param, int i)
{
    int nbName = 0;
    i++;
    while (i < ac) {
        nbName++;
        param->name = (char **)realloc(param->name, sizeof(char *) * nbName + 1);
        param->name[nbName - 1] = malloc(sizeof(char) * strlen(av[i]));
        strcpy(param->name[nbName - 1], av[i]);
        param->name[nbName] = NULL;
        i++;
        if (strncmp(av[i], "-", 1) == 0) {
            i = ac;
        }
    }
}

/**
 * \fn void check_param_n(int ac, char **av, param_t *param);
 * \brief Trouve element name de la structure param_t
 *
 * \param ac nombre d'arguments
 * \param av arguments entrés en execution du programme
 * \param param_t structure qui contien les arguments passé en paramètres
 * \return void
 */

void check_param_n(int ac, char **av, param_t *param)
{
    int a;
    for (int i = 0 ; i< ac ; i ++) {
        if (strcmp(av[i], "-n") == 0) {
            // printf(" av[%d] : ‘%s’\n", i, av[i]);
            // printf("-n find\n");
            a = i;
            init_param_n(ac, av, param, a);
            i = ac;
        }
    }
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
        check_param_n(ac, av, param);
        check_param(ac, av, param);
    }
}