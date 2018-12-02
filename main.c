/*
** EPITECH PROJECT, 2018
** 102 architect
** File description:
** compute points images in the plan after several transformations
*/

#include "include/my.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct point {
    float x;
    float y;
} point_t;

void print_matrix(double **matrix);

void translation(point_t point1, point_t point2, double **matrix, double **rslt)
{
    point_t result;

    matrix[0][0] =  matrix[0][0] + 1.00;
    matrix[2][2] = 1.00;
    matrix[1][1] = 1.00;
    matrix[0][2] = point2.x;
    matrix[1][2] = point2.y;

    printf("Translation along vector (%.0f, %.0f)\n", point2.x, point2.y);
    result.x = point1.x + point2.x;
    result.y = point1.y + point2.y;
    rslt = matrix;
    print_matrix(rslt);
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, result.x, result.y);
}

void scaling(point_t point1, point_t point2, double **matrix, double **rslt)
{
    point_t result;

    matrix[2][2] = 1.00;
    matrix[0][0] = point2.x;
    matrix[1][1] = point2.y;

    printf("Scaling by factors %.0f and %.0f\n", point2.x, point2.y);
    result.x = point1.x * point2.x;
    result.y = point1.y * point2.y;
    rslt = matrix;
    print_matrix(rslt);
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, result.x, result.y);
}

void rotation(point_t point1, double **matrix, double angle)
{
    matrix[0][0] = cos(angle);
    matrix[0][1] = -sin(angle);
    matrix[1][0] = sin(angle);
    matrix[1][1] = cos(angle);
    matrix[2][2] = 1;
    printf("Rotation by a %.0f degree angle\n", angle * 180 / M_PI);
    print_matrix(matrix);
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, point1.y, point1.x);
}

void print_matrix(double **matrix)
{
    for (int i = 0; i != 3; i++) {
        for (int j = 0; j != 3; j++) {
            printf("%.2f", matrix[i][j]);
            if (j != 2)
                printf("\t");
        }
        printf("\n");
    }
}

double **init_matrice(double **matrix)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            matrix[i][j] = 0.00;
    }
    return (matrix);
}

void reflexion(point_t point1, double **matrix, double angle)
{
    matrix[0][0] = (cos(2 * angle));
    matrix[0][1] = (sin(2 * angle));
    matrix[1][0] = (sin(2 * angle));
    matrix[1][1] = (-cos(2 * angle));
    matrix[2][2] = 1;
    printf("Reflection over an axis with an inclination angle of %.0f degrees\n", angle* 180 / M_PI);
    print_matrix(matrix);
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", point1.x, point1.y, point1.x * point1.y, point1.y);
}

void my_get_arg(int ac, char **av, double **matrix, double **rslt, point_t point1, point_t point2)
{
    for (int i = 0; i != ac; i++) {
        if (strcmp(av[i], "-t") == 0) {
            point1.x = atof(av[i - 2]);
            point1.y = atof(av[i - 1]);
            point2.x = atof(av[i + 1]);
            point2.y = atof(av[i + 2]);
            translation(point1, point2, matrix, rslt);
        } else if (strcmp(av[i], "-r") == 0) {
            point1.y = atof(av[i - 1]);
            point1.x = atof(av[i - 2]);
            double angle = atoi(av[i + 1]);
            angle = angle * (M_PI /180);
            rotation(point1, matrix, angle);
        } else if (strcmp(av[i], "-z") == 0) {
            point1.x = atof(av[i - 2]);
            point1.y = atof(av[i - 1]);
            point2.x = atof(av[i + 1]);
            point2.y = atof(av[i + 2]);
            scaling(point1, point2, matrix, rslt);
        } else if (strcmp(av[i], "-s") == 0) {
            point1.y = atof(av[i - 1]);
            point1.x = atof(av[i - 2]);
            double angle = atoi(av[i + 1]);
            angle = angle * (M_PI /180);
            reflexion(point1, matrix, angle);
        }
    }
}

int main(int ac, char **av)
{
    point_t point1 = {0, 0};
    point_t point2 = {0, 0};;
    double **matrix1 = malloc(sizeof(double *) * 3);
    double **matrix2 = malloc(sizeof(double *) * 3);
    double **rslt = malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++) {
        matrix1[i] = malloc(sizeof(double) * 3);
        matrix2[i] = malloc(sizeof(double) * 3);
        rslt[i] = malloc(sizeof(double) * 3);
    }
    init_matrice(rslt);
    init_matrice(matrix1);
    init_matrice(matrix2);

    my_get_arg(ac, av, matrix1, rslt, point1, point2);
    return (0);
}