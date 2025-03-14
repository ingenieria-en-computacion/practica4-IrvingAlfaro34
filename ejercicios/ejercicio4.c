#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 40  

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
} Estudiante;

int main() {
    int size = 2;  
    Estudiante *estudiantes = (Estudiante *)malloc(size * sizeof(Estudiante));

    if (estudiantes == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char continuar;

    printf("Ingrese los datos de los estudiantes (Nombre y Edad). Para salir, ingrese 'n' como nombre.\n");

    while (1) {
        Estudiante temp;
        printf("\nIngrese nombre: ");
        scanf(" %[^\n]", temp.nombre);  

        if (strcmp(temp.nombre, "n") == 0) break;  

        printf("Ingrese edad: ");
        scanf("%d", &temp.edad);

       
        if (count >= size) {
            size *= 2;  
            Estudiante *tempPtr = (Estudiante *)realloc(estudiantes, size * sizeof(Estudiante));
            if (tempPtr == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                free(estudiantes);
                return 1;
            }
            estudiantes = tempPtr;
        }

        
        estudiantes[count++] = temp;
    }

    printf("\nLista de estudiantes ingresados:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", estudiantes[i].nombre, estudiantes[i].edad);
    }

    free(estudiantes);

    return 0;
}
