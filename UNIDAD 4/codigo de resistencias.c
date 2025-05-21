#include <stdio.h>

int main() {
    int n;
    printf("¿Cuántas resistencias en paralelo vas a ingresar?: ");
    scanf("%d", &n);

    double resistencia, sumaInversos = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor de la resistencia %d (en ohmios): ", i + 1);
        scanf("%lf", &resistencia);

        if (resistencia != 0) {
            sumaInversos += 1.0 / resistencia;
        } else {
            printf("La resistencia no puede ser cero (división por cero).\n");
            return 1;  // termina el programa con error
        }
    }

    double Req = 1.0 / sumaInversos;
    printf("La resistencia equivalente en paralelo es: %.2f ohmios\n", Req);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *nombreCurso;
    char *temp;
    int tamaño = 100;
    int nrc;

    // 1. Reservar memoria inicial para el nombre del curso
    nombreCurso = (char *)malloc(tamaño * sizeof(char));
    if (nombreCurso == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // 2. Solicitar y guardar el nombre del curso
    printf("Ingrese el nombre del curso: ");
    fgets(nombreCurso, tamaño, stdin);
    nombreCurso[strcspn(nombreCurso, "\n")] = 0; // Eliminar el salto de línea

    // 3. Redimensionar memoria para que el nombre quepa exacto
    temp = realloc(nombreCurso, (strlen(nombreCurso) + 1) * sizeof(char));
    if (temp == NULL) {
        printf("Error al redimensionar memoria.\n");
        free(nombreCurso);
        return 1;
    }
    nombreCurso = temp;

    // 4. Solicitar el código NRC del curso
    printf("Ingrese el código NRC del curso: ");
    scanf("%d", &nrc);

    // 5. Redimensionar memoria para guardar también el NRC (como cadena)
    int nuevoTamaño = strlen(nombreCurso) + 1 + 10; // +10 para convertir el NRC a texto
    temp = realloc(nombreCurso, nuevoTamaño * sizeof(char));
    if (temp == NULL) {
        printf("Error al redimensionar memoria para NRC.\n");
        free(nombreCurso);
        return 1;
    }
    nombreCurso = temp;

    // Agregar el NRC al final del nombre del curso
    sprintf(nombreCurso + strlen(nombreCurso), " %d", nrc);

    printf("Curso completo: %s\n", nombreCurso);

    // Liberar memoria
    free(nombreCurso);
    return 0;
}
