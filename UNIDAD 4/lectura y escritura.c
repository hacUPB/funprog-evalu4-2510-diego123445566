#include <stdio.h>

float main(void)
{
    FILE *p_imc = fopen("imc.txt", "w");

    if (!p_imc)
    {
        perror("No se pudo crear imc.txt");
        return 1;
    }

    // Escribir los IMC directamente
    fprintf(p_imc, "%.2f\n", 23.00);
    fprintf(p_imc, "%.2f\n", 22.7);
    fprintf(p_imc, "%.2f\n", 18.4);

    fclose(p_imc);

    printf("Archivo imc.txt creado con éxito.\n");
    return 0;
}
