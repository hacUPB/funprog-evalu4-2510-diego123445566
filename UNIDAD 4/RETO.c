#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mostrarMenu();
int main() {
    int opcion;
    while (1) {
        mostrarMenu();
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            // Si no se puede leer un número, limpiamos el buffer y mostramos un error
            while(getchar() != '\n'); // Limpiar el buffer de entrada
            printf("Entrada inválida. Por favor ingrese un número.\n");
            continue; // Volver a mostrar el menú
        }
        switch (opcion) {
            case 1:
                printf("Cargar archivo de texto (opción 1)\n");
                break;
            case 2:
                printf("Calcular estadísticas del texto (opción 2)\n");
                break;
            case 3:
                printf("Calcular la frecuencia de vocales (opción 3)\n");
                break;
            case 4:
                printf("Reemplazar palabra en el texto (opción 4)\n");
                break;
            case 5:
                printf("Guardar resultados en archivo (opción 5)\n");
                break;
            case 6:
                printf("Saliendo...\n");
                exit(0);
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    }
    return 0;
}
// Función para mostrar el menú
void mostrarMenu() {
    printf("\n--- Análisis de Texto en Consola ---\n");
    printf("1. Cargar archivo de texto\n");
    printf("2. Calcular estadísticas del texto\n");
    printf("3. Calcular la frecuencia de vocales\n");
    printf("4. Reemplazar palabra en el texto\n");
    printf("5. Guardar resultados en archivo\n");
    printf("6. Salir\n");
}

// FUNCIONES
// Función para cargar un archivo de texto
void cargarArchivo(char **contenido, int *tamano) {
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Obtener el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    *tamano = ftell(archivo); // Tamaño del archivo
    fseek(archivo, 0, SEEK_SET); // Volver al inicio del archivo

    // Asignar memoria dinámica para el contenido del archivo
    *contenido = (char *)malloc(*tamano + 1); // +1 para el terminador '\0'
    if (*contenido == NULL) {
        printf("Error de memoria.\n");
        fclose(archivo);
        return;
    }

    // Leer el archivo y almacenarlo en el arreglo de caracteres
    fread(*contenido, 1, *tamano, archivo);
    (*contenido)[*tamano] = '\0'; // Asegurar que el texto termine en null

    fclose(archivo);
    printf("Archivo cargado correctamente.\n");
}

// Función para calcular estadísticas del texto
void calcularEstadisticas(char *contenido) {
    if (contenido == NULL) {
        printf("No hay texto cargado para analizar.\n");
        return;
    }

    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int enPalabra = 0; // Variable para detectar el inicio de una palabra

    for (int i = 0; contenido[i] != '\0'; i++) {
        if (contenido[i] != '\n') {
            caracteres++; // Contar caracteres (excepto saltos de línea)
        }

        if (contenido[i] == ' ') {
            espacios++; // Contar los espacios
        }

        if (contenido[i] == '\n') {
            lineas++; // Contar las líneas
        }

        // Contar las palabras
        if ((contenido[i] != ' ' && contenido[i] != '\n') && !enPalabra) {
            palabras++; // Si encontramos un carácter no blanco y no estamos en una palabra
            enPalabra = 1; // Estamos dentro de una palabra
        } else if (contenido[i] == ' ' || contenido[i] == '\n') {
            enPalabra = 0; // Fin de una palabra
        }
    }

    // Si el archivo no termina con un salto de línea, debemos contar la última línea
    if (contenido[strlen(contenido) - 1] != '\n') {
        lineas++;
    }

    printf("\nEstadísticas del texto:\n");
    printf("Total de caracteres: %d\n", caracteres);
    printf("Total de palabras: %d\n", palabras);
    printf("Total de espacios: %d\n", espacios);
    printf("Total de líneas: %d\n", lineas);
}

// Contar la frecuencia de vocales

void contarVocales(char *contenido) {
    if (contenido == NULL) {
        printf("No hay texto cargado para analizar.\n");
        return;
    }

    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int j = 0; contenido[j] != '\0'; j++) {
        char c = tolower(contenido[j]);
        if (c == 'a') a++;
        else if (c == 'e') e++;
        else if (c == 'i') i++;
        else if (c == 'o') o++;
        else if (c == 'u') u++;
    }

    printf("\nFrecuencia de vocales:\n");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}

