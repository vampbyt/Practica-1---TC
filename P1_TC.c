#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ConcatenarCadenas(char* cadena1, char* cadena2) {
    char cadenaNueva[100];
    strcpy(cadenaNueva, cadena1);
    strcat(cadenaNueva, cadena2);
    printf("La concatenación de las cadenas es: %s\n", cadenaNueva);
    printf("¿Deseas saber su longitud? (Y/N): ");
    char x;
    scanf(" %c", &x);
    if (x == 'Y' || x == 'y') {
        printf("La longitud de la cadena concatenada es: %d\n", strlen(cadenaNueva));
    } else if (x == 'N' || x == 'n') {
        printf("¡Gracias por usar el programa!\n");
    } else {
        printf("Opción no válida.\n");
    }
}

void PotenciaCadenas(char* cadena1, char* cadena2){
    printf("Sean sus cadenas las siguientes: ");
    printf("Cadena 1: %s\n", cadena1);
    printf("Cadena 2: %s\n", cadena2);
    printf("¿Cuál de las dos cadenas desea potenciar? (1 o 2): ");
    int angel;
    scanf("%d", &angel);
    switch (angel) {
        case 1:
            printf("Ingrese la potencia a la que desea elevar la cadena 1(+ o -): ");
            int k;
            scanf("%d", &k);
            if (k > 0) {
                char cadenaPotencia[100]= "";
                for (int i = 0; i < k; i++){
                    strcat(cadenaPotencia, cadena1);
                }
                printf("La potencia positiva de la cadena 1 es: %s\n", cadenaPotencia);
            } else if (k < 0) {
                char cadenaPotencia[100]= "";
    char invertida[100];
    int len = strlen(cadena1);

    for (int i = 0; i < len; i++) {
        invertida[i] = cadena1[len - 1 - i];
    }
    invertida[len] = '\0';

    for (int i = 0; i < -k; i++){
        strcat(cadenaPotencia, invertida);
    }
    printf("La potencia negativa de la cadena 1 es: %s\n", cadenaPotencia);
}
        break;
        case 2:
            printf("Ingrese la potencia a la que desea elevar la cadena 2(+ o -): ");
            int m;
            scanf("%d", &m);
            if (m > 0) {
                char cadenaPotencia[100]= "";
                for (int i = 0; i < m; i++){
                    strcat(cadenaPotencia, cadena2);
                }
                printf("La potencia positiva de la cadena 2 es: %s\n", cadenaPotencia);
            } else if (m < 0) {
                char cadenaPotencia[100]= "";
                char invertida[100];
                int len = strlen(cadena2);

                for (int i = 0; i < len; i++) {
                    invertida[i] = cadena2[len - i - 1];
                }
                invertida[len] = '\0';

                for (int i = 0; i < -m; i++){
                    strcat(cadenaPotencia, invertida);
                }
                printf("La potencia negativa de la cadena 2 es: %s\n", cadenaPotencia);
            } else {
                printf("La potencia de una cadena a la 0 es la cadena vacía.\n");
            }
        break;
        default: 
        printf("Opción no válida.\n");
        break;
    }
}

void LongitudCadenas(char* cadena1, char* cadena2){
    printf("La longitud de la cadena 1 es: %lu\n", strlen(cadena1));
    printf("La longitud de la cadena 2 es: %lu\n", strlen(cadena2));
}

void PrefijosSufijos(char* cadena1, char* cadena2){
    //Los prefijos se obtienen al eliminar cero o más símbolos del final de la cadena.
    //Los sufijos se obtienen al eliminar cero o más símbolos del inicio de la cadena.
    printf("¿De qué cadena desea obtener los prefijos y sufijos? (1 o 2): ");
    int opcion;
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("Los prefijos de la cadena 1 son: \n");
            for (int i = 0; i <= strlen(cadena1); i++) {
                char prefijo[50];
                strncpy(prefijo, cadena1, i);
                prefijo[i] = '\0';
                printf("%s\n", prefijo);
            }
            printf("Los sufijos de la cadena 1 son: \n");
            for (int i = 0; i <= strlen(cadena1); i++) {
                char sufijo[50];
                strncpy(sufijo, cadena1 + i, strlen(cadena1) - i);
                sufijo[strlen(cadena1) - i] = '\0';
                printf("%s\n", sufijo);
            }
        break;
        case 2:
            printf("Los prefijos de la cadena 2 son: \n");
            for (int i = 0; i <= strlen(cadena2); i++) {
                char prefijo[50];
                strncpy(prefijo, cadena2, i);
                prefijo[i] = '\0';
                printf("%s\n", prefijo);
            }
            printf("Los sufijos de la cadena 2 son: \n");
            for (int i = 0; i <= strlen(cadena2); i++) {
                char sufijo[50];
                strncpy(sufijo, cadena2 + i, strlen(cadena2) - i);
                sufijo[strlen(cadena2) - i] = '\0';
                printf("%s\n", sufijo);
            }
        break;
        default:
        printf("Opción no válida.\n");
        break;
    }
}

void Subcadenas(char* cadena1, char* cadena2){
    printf("Las subcadenas de la cadena 1 son: \n");
    for (int i = 0; i < strlen(cadena1); i++) {
        for (int j = i; j < strlen(cadena1); j++) {
            char subcadena[50];
            strncpy(subcadena, cadena1 + i, j - i + 1);
            subcadena[j - i + 1] = '\0';
            printf("%s\n", subcadena);
        }
    }
    printf("Las subcadenas de la cadena 2 son: \n");
    for (int i = 0; i < strlen(cadena2); i++) {
        for (int j = i; j < strlen(cadena2); j++) {
            char subcadena[50];
            strncpy(subcadena, cadena2 + i, j - i + 1);
            subcadena[j - i + 1] = '\0';
            printf("%s\n", subcadena);
        }
    }
}

void Subsecuencias(char* cadena1, char* cadena2){
    printf("Las subsecuencias de la cadena 1 son: \n");
    for (int i = 0; i < (1 << strlen(cadena1)); i++) {
        char subsecuencia[50];
        int index = 0;
        for (int j = 0; j < strlen(cadena1); j++) {
            if (i & (1 << j)) {
                subsecuencia[index++] = cadena1[j];
            }
        }
        subsecuencia[index] = '\0';
        printf("%s\n", subsecuencia);
    }
    printf("Las subsecuencias de la cadena 2 son: \n");
    for (int i = 0; i < (1 << strlen(cadena2)); i++) {
        char subsecuencia[50];
        int index = 0;
        for (int j = 0; j < strlen(cadena2); j++) {
            if (i & (1 << j)) {
                subsecuencia[index++] = cadena2[j];
            }
        }
        subsecuencia[index] = '\0';
        printf("%s\n", subsecuencia);
    }
}

void Menu(char* cadena1, char* cadena2) {
    int ab;

    do {
        printf("¿Qué operación desea realizar?\n");
    printf("1.- Concatenar cadenas\n");
    printf("2.- Potencia de cadenas (positiva y negativa)\n");
    printf("3.- Calculo de longitud de cadenas.\n");
    printf("4.- Generación de prefijos y sufijos de una cadena.\n");
    printf("5.- Generación de subcadenas.\n");
    printf("6.- Generación de subsecuencias.\n");
    scanf("%d", &ab);

    switch (ab) {
    case 1:ConcatenarCadenas(cadena1, cadena2);break;
    case 2:PotenciaCadenas(cadena1, cadena2); break;
    case 3:LongitudCadenas(cadena1, cadena2); break;
    case 4:PrefijosSufijos(cadena1, cadena2); break;
    case 5:Subcadenas(cadena1, cadena2);break;
    case 6:Subsecuencias(cadena1, cadena2); break;
    default:
        printf("Opción no válida.\n");
        break;
    }
    } while (ab != 7);

} 

int main (){
    printf("Hola, bienvenido al menú de procesamiento de cadenas.\n");
    printf("Ingrese su cadena 1: ");

    char cadena1[50];
    scanf("%s", cadena1);

    printf("Ingrese la cadena 2: ");
    char cadena2[50];
    scanf("%s", cadena2);

    printf("La cadena 1 es: %s\n", cadena1);
    printf("La cadena 2 es: %s\n", cadena2);

    Menu(cadena1, cadena2);

    return 0;
}