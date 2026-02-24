#include <stdio.h>
#include <stdlib.h>
#include "alfabets_cadens_hc.h"

int main (){
    CADENAS_LIST misDatos;
    
    // Inicializamos las cadenas apuntando a NULL para que realloc sepa que es la primera vez
    misDatos.cadena1 = NULL;
    misDatos.cadena2 = NULL;
    
    char bufferEntrada[200]; 
    int entradasValidas = 0;

    presen();

    printf("Hola, bienvenido al menú de procesamiento de cadenas.\n");

    while(!entradasValidas) {
        printf("\nIngrese su cadena 1 (alfanumérica, max 49 chars): ");
        scanf("%s", bufferEntrada);
        
        int len1 = calcular_longitud_cadena(bufferEntrada);

        if (len1 >= 50) {
            printf("Error: Las cadenas deben ser menores a 50 caracteres.\n");
            continue; 
        } else if (!esAlfanumerica(bufferEntrada)) {
            printf("Error: El alfabeto solo permite letras y números (sin simbolos especiales).\n");
            continue;
        }
        
        // Asignamos memoria dinámica exacta a cadena1 usando la información validada
        misDatos.cadena1 = (char*)malloc((len1 + 1) * sizeof(char));
        copiar_cadena(misDatos.cadena1, bufferEntrada);

        printf("Ingrese su cadena 2 (alfanumérica, max 49 chars): ");
        scanf("%s", bufferEntrada);
        
        int len2 = calcular_longitud_cadena(bufferEntrada);

        if (len2 >= 50) {
            printf("Error: Las cadenas deben ser menores a 50 caracteres.\n");
            // Si la 2 falla, liberamos la 1 antes de reiniciar el ciclo para no dejar basura
            free(misDatos.cadena1); 
            continue;
        } else if (!esAlfanumerica(bufferEntrada)) {
            printf("Error: El alfabeto solo permite letras y números.\n");
            free(misDatos.cadena1);
            continue;
        }

        misDatos.cadena2 = (char*)malloc((len2 + 1) * sizeof(char));
        copiar_cadena(misDatos.cadena2, bufferEntrada);
        
        entradasValidas = 1; 
    }

    Menu(&misDatos);

    // Al final del programa, regresamos toda la memoria usada al sistema
    free(misDatos.cadena1);
    free(misDatos.cadena2);

    return 0;
}
