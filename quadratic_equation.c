#include "quadratic_equation.h"

char* solve_equation(double a, double b, double c) {
    int D;
    char answer[255];
    double result;
    D = b * b - 4 * a * c;
    if (D == 0) {
        result = -b / (2 * a);
        sprintf(answer, "%f", result);
    } else if (D < 0) {
        strcpy(answer, "No solution");
    } else {
        result = (-b - sqrt(D)) / (2 * a);
        sprintf(answer, "%f", result);
        result = (-b + sqrt(D)) / (2 * a);
        char answer_2[255];
        sprintf(answer_2, "%f", result);
        strcat(answer, " ");
        strcat(answer, answer_2);
    }
    return strdup(answer);
}