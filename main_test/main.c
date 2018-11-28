/*
** EPITECH PROJECT, 2018
** 102 architect
** File description:
** compute points images in the plan after several transformations
*/

#include "include/my.h"

typedef struct point {
    float x;
    float y;
} point_t;

void translation(point_t point1, point_t point2)
{
    point_t result;

    printf("Translation along vector (%.0f, %.0f)\n", point2.x, point2.y);
    result.x = point1.x + point2.x;
    result.y = point1.y + point2.y;
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, result.x, result.y);
}

void scaling(point_t point1, point_t point2)
{
    point_t result;

    printf("Scaling by factors %.0f and %.0f\n", point2.x, point2.y);
    result.x = point1.x * point2.x;
    result.y = point1.y * point2.y;
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, result.x, result.y);
}

void my_get_arg(double **matrix)
{
    for(int i = 0; i < ac; i++) {
        if (av[0][i] == t) {
            printf("ttttt");
        if (av[0][i] == z)
            printf("zzzz");
        if (av[0][i] == s)
            printf("sssss");
        }
    }
    
}


/*void print_matrix()
{

}*/

int main(int ac, char **av)
{
    point_t point1;
    point_t point2;
    char *option;

    point1.x = atof(av[1]);
    point1.y = atof(av[2]);

    point2.x = atof(av[4]);
    point2.y = atof(av[5]);

    option = av[3];

    //translation(point1, point2);
    scaling(point1, point2);
    return (0);
}