#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    // Pedir al usuario el tamaño de la matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &n);

    
    if (m <= 0 || n <= 0) {
        printf("Error: Las dimensiones deben ser mayores que 0.\n");
        return 1;
    }

    
    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

   
    printf("\nMatriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }

    
    int row, col, value;
    printf("\nIngrese las coordenadas (fila columna) y el valor a modificar (ej. 1 2 5): ");
    if (scanf("%d %d %d", &row, &col, &value) != 3) {
        printf("Error: Entrada inválida.\n");
        free(matrix);
        return 1;
    }

   
    if (row < 1 || row > m || col < 1 || col > n) {
        printf("Error: Coordenadas fuera de rango.\n");
    } else {
        matrix[(row - 1) * n + (col - 1)] = value;
    }

    
    printf("\nMatriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }

    free(matrix);

    return 0;
}
