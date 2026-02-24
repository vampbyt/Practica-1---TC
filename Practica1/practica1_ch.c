#include <stdio.h>
#include <stdlib.h>
#include "alfabets_cadens_hc.h"

int main (){
    CADENAS_LIST misDatos;
    
    // Inicializamos las cadenas apuntando a NULL para que realloc sepa que es la primera vez
    misDatos.cadena1 = NULL;
    misDatos.cadena2 = NULL;
    
    char entrada[200]; 
    int entradasValidas = 0;

    presen();

    printf("Presiona Enter para continuar...");
    getchar();
    system("clear");

    while(!entradasValidas) {
        bienve();
        printf("Deberas ingresar las cadenas con las que vas a trabajar.\n");
        printf("Ingrese cadena 1 (alfanumérica, maximo 49): ");
        scanf("%s", entrada);
        
        int len1 = calcular_longitud_cadena(entrada);

        if (len1 >= 50) {
            printf("----> Error: Las cadenas deben ser menores a 50 caracteres.\n");
            continue; 
        } else if (!esAlfanumerica(entrada)) {
            printf("----> Error: El alfabeto solo permite letras y números.\n");
            continue;
        }
        
        // Asignamos memoria dinámica exacta a cadena1 usando la información validada
        misDatos.cadena1 = (char*)malloc((len1 + 1) * sizeof(char));
        copiar_cadena(misDatos.cadena1, entrada);

        printf("Ingrese cadena 2 (alfanumérica, maximo 49): ");
        scanf("%s", entrada);
        
        int len2 = calcular_longitud_cadena(entrada);

        if (len2 >= 50) {
            printf("----> Error: Las cadenas deben ser menores a 50 caracteres.\n");
            // Si la 2 falla, liberamos la 1 antes de reiniciar el ciclo para no dejar basura
            free(misDatos.cadena1); 
            continue;
        } else if (!esAlfanumerica(entrada)) {
            printf("----> Error: El alfabeto solo permite letras y números.\n");
            free(misDatos.cadena1);
            continue;
        }

        misDatos.cadena2 = (char*)malloc((len2 + 1) * sizeof(char));
        copiar_cadena(misDatos.cadena2, entrada);
        
        entradasValidas = 1; 
    }

    system("clear");
    Menu(&misDatos);

    // Al final del programa, regresamos toda la memoria usada al sistema
    free(misDatos.cadena1);
    free(misDatos.cadena2);

    return 0;
}
