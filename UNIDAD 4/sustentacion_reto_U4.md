1. Explicación del análisis del problema:

    Describan, con sus propias palabras, cómo entendieron el problema, qué decisiones tomaron para resolverlo y por qué.

ENTENDIMIENTO DEL PROBLEMA:

 El objetivo era crear un programa en C que permitiera realizar un análisis de texto desde la consola. Esto incluye: cargar un archivo de texto, calcular estadísticas básicas (caracteres, palabras, líneas, espacios), contar la frecuencia de vocales, reemplazar una palabra por otra en el texto, y guardar los resultados en un nuevo archivo.
 
DECISIONES QUE TOME:

Modularizar el código en funciones para hacerlo más organizado y reutilizable.

Use una memoria dinamica para manejar archivos de texto de tamaño variable

Utilice estructuras de control para validar entradas y evitar errores en tiempo de ejecución.

Mantuve la simplicidad y eficiencia usando funciones estándar de C (fopen, fread, strstr, etc.).

PORQUE:

Porque busque que el programa fuera flexible, seguro y escalable, capaz de manejar archivos de tamaño variable, que interactuara eficientemente con el usuario que realizara operaciones de análisis sin perder precisión ni modificar el contenido original. La modularización mejora el orden del código, el uso de memoria dinámica lo hace más adaptable, y los métodos manuales para contar y reemplazar brindan control total sobre los resultados.

2. Estrategia de solución:
    
 Expliquen el enfoque general del código: estructura, módulos o funciones principales, cómo se conectan y cuál es su propósito

 Estructura general del código:

El main() gestiona el menú y el ciclo de ejecución.

Cada funcionalidad (cargar archivo, calcular estadísticas, etc.) se implementa como una función independiente.


Módulos principales y conexiones:

mostrarMenu(): Imprime las opciones disponibles.

cargarArchivo(): Carga el contenido del archivo a memoria.

calcularEstadisticas(): Analiza el contenido cargado.

contarVocales(): Cuenta frecuencias de las vocales.

reemplazarPalabra(): Reemplaza todas las ocurrencias de una palabra.

guardarResultados(): Escribe estadísticas y texto modificado a un archivo de salida.

como se conectan y cual es su proposito:

las funciones se conectan mediante llamadas desde el main() dependiendo de la opción seleccionada por el usuario.

y su proposito es principalmente sobre el contenido del texto almacenado dinámicamente en un puntero char *contenido

3. Tabla de variables:
    
 Incluyan una tabla por cada función implementada donde se indiquen claramente las variables de entrada y salida:

Tabla de variables
```
Función: main

Variable                                   Tipo             Rol

opcion                                     int              Entrada del usuario (selección de menú)
contenido                                  char*            Entrada/Salida: Contenido cargado del archivo
tamaño                                     int              Salida: Tamaño del archivo cargado
caracteres,palabras,espacios,lineas        int              Salida: Estadísticas del texto
frecuencia de vocales                      int[5]           Salida: Frecuencia de a, e, i, o, u
```
Funcion:mostrar menu
```
Variable                                   Tipo             Rol
-                                          -                solo imprime el menu en pantalla
```
Funcion:cargar archivo
```
Variable                                   Tipo             Rol

contenido                                  char**           Salida: Puntero al contenido del archivo
tamaño                                     int*             Salida: Tamaño del archivo en bytes
nombre del archivo                         char[100]        Entrada: Nombre del archivo a cargar
archivo                                    FILE*            interna: Manejador de archivo
*contenido                                 char*            Interna: Almacena contenido leído
```

Funcion:calcular estadistica 
```
Variable                                   Tipo            Rol

contenido                                  char*           Entrada: Texto cargado
caracteres, palabras, espacios, lineas     int*            Salida: Estadísticas del texto
palabra                                    int             Interna: Flag para identificar inicio de palabra


Funcion:contar vocales

Variable                                   Tipo           Rol

contenido                                  char*          Entrada: Texto cargado
frecuencia                                 int*           Salida: Frecuencia de vocales
c                                          char           Interna: Caracter en minúscula actual del texto
```
Funcion:reemplazar palabra
```
Variable                                              Tipo                Rol

contenido                                             char**              Entrada/Salida: Texto a modificar
palabrabuscar                                         const char*         Entrada: Palabra a buscar
palabrareemplazo                                      const char*         Entrada: Palabra para reemplazar
resultado final                                       char*               Interna: Nuevo contenido modificado
actual, inicio, posicion, destino, temp               char                Internas: Manejo de posición en texto
lenBuscar, lenReemplazo, ocurrencias, nuevoTamanon    int                 Internas: Cálculos de reemplazo
```

Funcion: guardar resultado
```
Variable                                             Tipo                 Rol

contenido                                            const char*          Entrada: Texto modificado
caracteres, palabras, espacios, lineas               int                  Entrada: Estadísticas del texto
frecuencia de vocales                                int*                 Entrada: Frecuencia de vocales
nombreSalida                                         char[100]            Entrada: Nombre del archivo de salida
salida                                               FILE*                Interna: Manejador del archivo de salida

```
4. Diagramas, esquemas o pseudocódigo:

    Inserten cualquier gráfico, diagrama de flujo, estructura modular o pseudocódigo utilizado en el análisis. (Pueden ser imágenes incrustadas si las dibujaron a mano o con herramientas digitales).
   
```
inicializar variables
loop:
    mostrarMenu()
    leer opcion
    segun opcion:
        1 -> cargarArchivo
        2 -> calcularEstadisticas
        3 -> contarVocales
        4 -> leer palabraBuscar y palabraReemplazo
             reemplazarPalabra
        5 -> guardarResultados
        6 -> salir del programa
```
6. Lenguaje:
    
 Utilicen un lenguaje técnico, claro y conciso. Eviten explicaciones extensas que no aporten al análisis.

 Se ha utilizado un enfoque modular y orientado a funciones en lenguaje C. El uso de punteros y memoria dinámica permite manejar archivos de tamaño variable de forma eficiente. Las funciones de la biblioteca estándar aseguran portabilidad y fiabilidad. La validación de entradas y el manejo de errores garantizan robustez.



