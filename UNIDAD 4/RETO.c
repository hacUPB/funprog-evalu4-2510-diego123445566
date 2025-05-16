<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Necesario para tolower()

void mostrarMenu();
void cargarArchivo(char **contenido, int *tamano);
void calcularEstadisticas(char *contenido, int *caracteres, int *palabras, int *espacios, int *lineas);
void contarVocales(char *contenido, int *frecuenciasVocales);
void reemplazarPalabra(char **contenido, const char *palabraBuscar, const char *palabraReemplazo);
void guardarResultados(const char *contenido, int caracteres, int palabras, int espacios, int lineas, int *frecuenciasVocales);

int main() {
    int opcion;
    char *contenido = NULL;
    int tamano = 0;
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int frecuenciasVocales[5] = {0}; // a, e, i, o, u

    while (1) {
        mostrarMenu();
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida. Por favor ingrese un número.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                cargarArchivo(&contenido, &tamano);
                break;
            case 2:
                calcularEstadisticas(contenido, &caracteres, &palabras, &espacios, &lineas);
                break;
            case 3:
                contarVocales(contenido, frecuenciasVocales);
                break;
            case 4: {
                char buscar[100], reemplazo[100];
                printf("Palabra a buscar: ");
                scanf("%s", buscar);
                printf("Palabra para reemplazar: ");
                scanf("%s", reemplazo);
                reemplazarPalabra(&contenido, buscar, reemplazo);
                break;
            }
            case 5:
                guardarResultados(contenido, caracteres, palabras, espacios, lineas, frecuenciasVocales);
                break;
            case 6:
                printf("Saliendo...\n");
                free(contenido);
                exit(0);
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    }
    return 0;
}

void mostrarMenu() {
    printf("\n--- Análisis de Texto en Consola ---\n");
    printf("1. Cargar archivo de texto\n");
    printf("2. Calcular estadísticas del texto\n");
    printf("3. Calcular la frecuencia de vocales\n");
    printf("4. Reemplazar palabra en el texto\n");
    printf("5. Guardar resultados en archivo\n");
    printf("6. Salir\n");
}

void cargarArchivo(char **contenido, int *tamano) {
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    *tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    *contenido = (char *)malloc(*tamano + 1);
    if (*contenido == NULL) {
        printf("Error de memoria.\n");
        fclose(archivo);
        return;
    }

    fread(*contenido, 1, *tamano, archivo);
    (*contenido)[*tamano] = '\0';

    fclose(archivo);
    printf("Archivo cargado correctamente.\n");
}

void calcularEstadisticas(char *contenido, int *caracteres, int *palabras, int *espacios, int *lineas) {
    if (contenido == NULL) {
        printf("No hay texto cargado para analizar.\n");
        return;
    }

    *caracteres = *palabras = *espacios = *lineas = 0;
    int enPalabra = 0;

    for (int i = 0; contenido[i] != '\0'; i++) {
        if (contenido[i] != '\n') (*caracteres)++;
        if (contenido[i] == ' ') (*espacios)++;
        if (contenido[i] == '\n') (*lineas)++;

        if ((contenido[i] != ' ' && contenido[i] != '\n') && !enPalabra) {
            (*palabras)++;
            enPalabra = 1;
        } else if (contenido[i] == ' ' || contenido[i] == '\n') {
            enPalabra = 0;
        }
    }

    if (contenido[strlen(contenido) - 1] != '\n') {
        (*lineas)++;
    }

    printf("\nEstadísticas del texto:\n");
    printf("Total de caracteres: %d\n", *caracteres);
    printf("Total de palabras: %d\n", *palabras);
    printf("Total de espacios: %d\n", *espacios);
    printf("Total de líneas: %d\n", *lineas);
}

void contarVocales(char *contenido, int *frecuencias) {
    if (contenido == NULL) {
        printf("No hay texto cargado para analizar.\n");
        return;
    }

    for (int j = 0; j < 5; j++) frecuencias[j] = 0;

    for (int j = 0; contenido[j] != '\0'; j++) {
        char c = tolower(contenido[j]);
        if (c == 'a') frecuencias[0]++;
        else if (c == 'e') frecuencias[1]++;
        else if (c == 'i') frecuencias[2]++;
        else if (c == 'o') frecuencias[3]++;
        else if (c == 'u') frecuencias[4]++;
    }

    printf("\nFrecuencia de vocales:\n");
    printf("a: %d\n", frecuencias[0]);
    printf("e: %d\n", frecuencias[1]);
    printf("i: %d\n", frecuencias[2]);
    printf("o: %d\n", frecuencias[3]);
    printf("u: %d\n", frecuencias[4]);
}
=======

>>>>>>> c8b1dd1202287c3deea527e107aab038c8c6c22c

void reemplazarPalabra(char **contenido, const char *palabraBuscar, const char *palabraReemplazo) {
    if (*contenido == NULL) {
        printf("No hay texto cargado para modificar.\n");
        return;
    }

    char *resultadoFinal = NULL;
    char *actual = *contenido;
    int lenBuscar = strlen(palabraBuscar);
    int lenReemplazo = strlen(palabraReemplazo);

    char *temp = actual;
    int ocurrencias = 0;
    while ((temp = strstr(temp, palabraBuscar)) != NULL) {
        ocurrencias++;
        temp += lenBuscar;
    }

    if (ocurrencias == 0) {
        printf("La palabra no se encontró en el texto.\n");
        return;
    }

    int nuevoTamano = strlen(*contenido) + ocurrencias * (lenReemplazo - lenBuscar) + 1;
    resultadoFinal = (char *)malloc(nuevoTamano);
    if (resultadoFinal == NULL) {
        printf("Error de memoria al intentar reemplazar.\n");
        return;
    }

    char *inicio = *contenido;
    char *posicion = NULL;
    char *destino = resultadoFinal;

    while ((posicion = strstr(inicio, palabraBuscar)) != NULL) {
        int bytesAntes = posicion - inicio;
        memcpy(destino, inicio, bytesAntes);
        destino += bytesAntes;

        memcpy(destino, palabraReemplazo, lenReemplazo);
        destino += lenReemplazo;

        inicio = posicion + lenBuscar;
    }

    strcpy(destino, inicio);

    free(*contenido);
    *contenido = resultadoFinal;

    printf("Se reemplazaron %d ocurrencias de \"%s\" por \"%s\".\n", ocurrencias, palabraBuscar, palabraReemplazo);
}

void guardarResultados(const char *contenido, int caracteres, int palabras, int espacios, int lineas, int *frecuenciasVocales) {
    if (contenido == NULL) {
        printf("No hay contenido cargado para guardar.\n");
        return;
    }

    char nombreSalida[100];
    printf("Ingrese el nombre del archivo de salida: ");
    scanf("%s", nombreSalida);

    FILE *salida = fopen(nombreSalida, "w");
    if (salida == NULL) {
        printf("No se pudo crear el archivo de salida.\n");
        return;
    }

    fprintf(salida, "=== Estadísticas del Texto ===\n");
    fprintf(salida, "Total de caracteres: %d\n", caracteres);
    fprintf(salida, "Total de palabras: %d\n", palabras);
    fprintf(salida, "Total de espacios: %d\n", espacios);
    fprintf(salida, "Total de líneas: %d\n\n", lineas);

    fprintf(salida, "=== Frecuencia de Vocales ===\n");
    fprintf(salida, "a/A: %d\n", frecuenciasVocales[0]);
    fprintf(salida, "e/E: %d\n", frecuenciasVocales[1]);
    fprintf(salida, "i/I: %d\n", frecuenciasVocales[2]);
    fprintf(salida, "o/O: %d\n", frecuenciasVocales[3]);
    fprintf(salida, "u/U: %d\n", frecuenciasVocales[4]);

    fprintf(salida, "\n=== Texto Modificado ===\n");
    fprintf(salida, "%s\n", contenido);

    fclose(salida);
    printf("Resultados guardados correctamente en '%s'.\n", nombreSalida);
}
