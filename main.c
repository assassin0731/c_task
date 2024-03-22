#include "quadratic_equation.h"

int main() {
    char* result = solve_equation(1, 3, 1);
    printf("%s\n", result);
    free(result);
    return 0;
}