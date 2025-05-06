#include <stdio.h>
#include <stdlib.h>

int main() {
    int letrasNombre, letrasApellido;
    char *nombre, *apellido;

    // Preguntar cuántas letras tiene el nombre y apellido
    printf("¿Cuántas letras tiene tu nombre? ");
    scanf("%d", &letrasNombre);
    printf("¿Cuántas letras tiene tu apellido? ");
    scanf("%d", &letrasApellido);

    // Reservar memoria (+1 para el carácter nulo '\0')
    nombre = (char *)malloc((letrasNombre + 1) * sizeof(char));
    apellido = (char *)malloc((letrasApellido + 1) * sizeof(char));

    // Validar si la memoria se reservó correctamente
    if (nombre == NULL || apellido == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Pedir al usuario que ingrese su nombre y apellido
    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    printf("Ingresa tu apellido: ");
    scanf("%s", apellido);

    // Imprimir saludo
    printf("¡Hola %s %s! Bienvenido al programa.\n", nombre, apellido);

    // Liberar la memoria
    free(nombre);
    free(apellido);

    return 0;
}