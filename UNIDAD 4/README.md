# Unidad No. 4 
Ingresa a continuación tu información.
## Información del estudiante  
Nombre del estudiante: DIEGO ALEJANDRO ALVARADO MONTOYA
Id.:000483783
---
## Descripción del contenido del repositorio  
No olvides realizar una descripción de lo que se encontrará dentro de tu repositorio.ACTIVIDADES

Actividad 1

Investiga y prepara un informe breve (puedes usar texto, código y ejemplos gráficos) sobre las siguientes funciones:

De <string.h>:
 `strlen`, `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strchr`, `strstr`, `strtok`

De <ctype.h>:

`isalpha`, `isdigit`, `isalnum`, `islower`, `isupper`, `tolower`, `toupper`

En tu reporte explica claramente:

- ¿Para qué sirve la función?
- ¿Cuál es el prototipo de la función?
- ¿Qué parámetros recibe? Explica cada uno.
- Crea un ejemplo funcional completo para cada función.

Organiza la información claramente según tu propio criterio.


SOLUCION

A.<string.h>

<strlen>:

¿Para qué sirve la función?

Calcula la longitud de una cadena (sin contar el carácter nulo \0 al final).

¿Cuál es el prototipo de la función?

size_t strlen(const char *str);

¿Qué parámetros recibe?

str: Puntero a una cadena de caracteres que debe estar terminada en \0.

<strcpy>:

¿Para qué sirve la función?

Copia una cadena de caracteres (src) a otra (dest), incluyendo el carácter nulo.

¿Cuál es el prototipo de la función?

char *strcpy(char *dest, const char *src);

¿Qué parámetros recibe?

dest: Puntero al destino donde se copiará la cadena.

src: Puntero a la cadena fuente.

<strncpy>

¿Para qué sirve la función?

Copia hasta n caracteres de una cadena a otra. Si src es menor a n, se rellena con \0.

¿Cuál es el prototipo de la función?

char *strncpy(char *dest, const char *src, size_t n);

¿Qué parámetros recibe?

dest: Cadena destino.

src: Cadena fuente.

n: Número máximo de caracteres a copiar.

<strcat>

¿Para qué sirve la función?
Agrega el contenido de una cadena al final de otra.

¿Cuál es el prototipo de la función?
char *strcat(char *dest, const char *src);

¿Qué parámetros recibe?

dest: Cadena a la que se agregará src.

src: Cadena que se añadirá.

<strncat>

¿Para qué sirve la función?

Agrega hasta n caracteres de una cadena al final de otra.

¿Cuál es el prototipo de la función?

char *strncat(char *dest, const char *src, size_t n);

¿Qué parámetros recibe?

dest: Cadena destino.

src: Cadena fuente.

n: Máximo de caracteres a agregar.

<strcmp>

¿Para qué sirve la función?

Compara dos cadenas de caracteres. Retorna:

0 si son iguales,

Un valor negativo si s1 < s2,

Un valor positivo si s1 > s2.

¿Cuál es el prototipo de la función?

int strcmp(const char *s1, const char *s2);

¿Qué parámetros recibe?

s1: Primera cadena.

s2: Segunda cadena.

<strncmp>

¿Para qué sirve la función?

Compara hasta n caracteres de dos cadenas.

¿Cuál es el prototipo de la función?

int strncmp(const char *s1, const char *s2, size_t n);

¿Qué parámetros recibe?

s1: Primera cadena.

s2: Segunda cadena.

n: Número máximo de caracteres a comparar.

<strchr>
¿Para qué sirve la función?

Busca la primera aparición de un carácter en una cadena.

¿Cuál es el prototipo de la función?

char *strchr(const char *str, int c);

¿Qué parámetros recibe?

str: Cadena en la que se busca.

c: Carácter que se quiere encontrar (como int, pero se convierte a char internamente).

<strstr>
¿Para qué sirve la función?

Busca una subcadena dentro de otra.

¿Cuál es el prototipo de la función?

char *strstr(const char *haystack, const char *needle);

¿Qué parámetros recibe?

haystack: Cadena principal.

needle: Subcadena a buscar.

<strtok>

¿Para qué sirve la función?

Divide una cadena en partes (tokens) usando delimitadores.

¿Cuál es el prototipo de la función?

char *strtok(char *str, const char *delim);

¿Qué parámetros recibe?

str: Cadena que se desea dividir (solo en la primera llamada).

delim: Caracteres delimitadores.

B.<ctype.h>

<isalpha>

¿Para qué sirve?: Verifica si es letra.

Prototipo: int isalpha(int c)

<isdigit>

¿Para qué sirve?: Verifica si es dígito.

Prototipo: int isdigit(int c)

<isalnum>
¿Para qué sirve?: Verifica si es letra o número.

Prototipo: int isalnum(int c)

<islower>

¿Para qué sirve?: Verifica si es minúscula.

Prototipo: int islower(int c)

<isupper>

¿Para qué sirve?: Verifica si es mayúscula.

Prototipo: int isupper(int c)

<tolower>

¿Para qué sirve?: Convierte a minúscula.

Prototipo: int tolower(int c)

<toupper>
¿Para qué sirve?: Convierte a mayúscula.

Prototipo: int toupper(int c)

Responde estas preguntas para asegurarte de que has comprendido bien el tema:

1. ¿Por qué `sizeof("Hola")` devuelve 5, pero `strlen("Hola")` devuelve 4?
2. ¿Cuál es la diferencia práctica entre declarar una cadena como arreglo (`char saludo[]`) y como puntero (`char *saludo`)?
3. ¿Cómo evitas un "buffer overflow" al copiar o concatenar cadenas?
4. ¿Qué hace exactamente la función `strcspn()` y por qué es útil usarla junto con `fgets()`?
5. ¿Qué pasos debes seguir para manejar correctamente una cadena reservada dinámicamente con `malloc()`?

SOLUCION 

1. sizeof("Hola") devuelve 5 porque cuenta todos los bytes que ocupa el string, incluyendo el carácter nulo '\0' al final.

strlen("Hola") devuelve 4 porque solo cuenta los caracteres visibles, no incluye el '\0'.

2. char saludo[] = "Hola";

El contenido "Hola" se copia en un arreglo local y se puede modificar.

char *saludo = "Hola";

El puntero apunta a una cadena constante en memoria. Modificarla causa comportamiento indefinido.

c
Copiar
Editar

3. Usa funciones seguras que permiten especificar el tamaño del buffer:

strncpy(dest, src, sizeof(dest) - 1); dest[sizeof(dest) - 1] = '\0';

strncat(dest, src, sizeof(dest) - strlen(dest) - 1);

Estas previenen escribir fuera del límite del arreglo.

4. strcspn(str, "\n") devuelve la posición del primer carácter de str que está en el conjunto "\n".

Útil con fgets() porque esta incluye el \n al final, y con strcspn() puedes quitarlo


## Ejercicios prácticos

Realiza los siguientes ejercicios para reforzar tus conocimientos:

1. **Contar vocales**: Escribe un programa que cuente el número de vocales en una cadena.
2. **Invertir cadena**: Implementa una función segura que invierta una cadena en otro arreglo.
3. **Palíndromo**: Detecta si una frase es un palíndromo (sin considerar espacios y puntuación).
4. **Conversión ASCII**: Convierte todas las letras minúsculas de una cadena a mayúsculas sin usar funciones de biblioteca.
5. **Tokenizador**: Implementa una versión simplificada de `strtok()` que separe una cadena por coma, punto y coma o espacios.

SOLUCION

vocales

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarVocales(const char *cadena) {
    int contador = 0;
    for (int i = 0; cadena[i]; i++) {
        char c = tolower(cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

int main() {
    char texto[100];
    printf("Ingrese una cadena: ");
    fgets(texto, sizeof(texto), stdin);
    printf("Cantidad de vocales: %d\n", contarVocales(texto));
    return 0;
}

invertir cadena

#include <stdio.h>
#include <string.h>

void invertirCadena(const char *original, char *invertida) {
    int len = strlen(original);
    for (int i = 0; i < len; i++) {
        invertida[i] = original[len - 1 - i];
    }
    invertida[len] = '\0';  // Finalizar la cadena
}

int main() {
    char texto[100], resultado[100];
    printf("Ingrese una cadena: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';  // Quitar salto de línea
    invertirCadena(texto, resultado);
    printf("Cadena invertida: %s\n", resultado);
    return 0;
}

palindromo

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esPalindromo(const char *frase) {
    char limpio[100], invertido[100];
    int j = 0;

    // Eliminar espacios y signos
    for (int i = 0; frase[i]; i++) {
        if (isalnum(frase[i])) {
            limpio[j++] = tolower(frase[i]);
        }
    }
    limpio[j] = '\0';

    // Invertir
    int len = strlen(limpio);
    for (int i = 0; i < len; i++) {
        invertido[i] = limpio[len - 1 - i];
    }
    invertido[len] = '\0';

    return strcmp(limpio, invertido) == 0;
}

int main() {
    char frase[100];
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    printf("¿Es palíndromo?: %s\n", esPalindromo(frase) ? "Sí" : "No");
    return 0;
}



