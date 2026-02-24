#include <stdio.h>
#include <stdlib.h>
#include "presentacion.h"

//ESTRCUTURA DINAMICA 
// FALTA AGREGAR OPCION DE CADENA EXTRA
typedef struct {
    char* cadena1;
    char* cadena2;
} CADENAS_LIST;


//=======================================
// FUNCIONES MANUALES DE CADENAS

int calcular_longitud_cadena(const char* cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}

void copiar_cadena(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; 
}

void copiar_cantidad_cadena(char* destino, const char* origen, int n) {
    int i = 0;
    while (i < n && origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    while (i < n) {
        destino[i] = '\0';
        i++;
    }
}

void pegar_cadena(char* destino, const char* origen) {
    int i = 0;
    while (destino[i] != '\0') {
        i++;
    }
    int j = 0;
    while (origen[j] != '\0') {
        destino[i] = origen[j];
        i++;
        j++;
    }
    destino[i] = '\0'; 
}

//=======================================

//=======================================
// FUNCIONES DE VALIDACION

int esAlfanumerica(const char* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!( (cadena[i] >= 'a' && cadena[i] <= 'z') || 
               (cadena[i] >= 'A' && cadena[i] <= 'Z') || 
               (cadena[i] >= '0' && cadena[i] <= '9') )) {
            return 0; 
        }
    }
    return 1; 
}

void GuardarResultado(CADENAS_LIST *datos, const char *resultado) {
    int opcion;
    system("clear");
    guardando();
    printf("\nDesea guardar este resultado???\n");
    printf("1.- Guardar en Cadena 1\n");
    printf("2.- Guardar en Cadena 2\n");
    printf("0.- No guardar\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    int len = calcular_longitud_cadena(resultado);

    if (opcion == 1) {
        int confirmar;
        printf("ADVERTENCIA: Esto sobreescribira la cadena seleccionada\n");
        printf("Estas seguro? (1 = SI) (0 = NO): ");
        scanf("%d", &confirmar);
        while (getchar() != '\n');
        if (confirmar == 1){
            // realloc ajusta la memoria de cadena1 al nuevo tamaño exacto
            datos->cadena1 = (char*)realloc(datos->cadena1, (len + 1) * sizeof(char));
            copiar_cadena(datos->cadena1, resultado);
            printf("¡Cadena 1 actualizada exitosamente!\n");
        }
        else {
            printf("Operacion de guardado cancelada\n");
            return;
        }

    } else if (opcion == 2) {
        int confirmar;
        printf("ADVERTENCIA: Esto sobreescribira la cadena seleccionada\n");
        printf("Estas seguro? (1 = SI) (0 = NO): ");
        scanf("%d", &confirmar);
        while (getchar() != '\n');
        if (confirmar == 1){
            datos->cadena2 = (char*)realloc(datos->cadena2, (len + 1) * sizeof(char));
            copiar_cadena(datos->cadena2, resultado);
            printf("Cadena 2 actualizada exitosamente\n");
        }
        else {
            printf("Operacion de guardado cancelada\n");
            return;
        }
    } else if (opcion == 0) {
        printf("Resultado no guardado\n");
        return;
    } else {
        printf("NO SELECCIONASTE NADA\n");
        printf("INTENTA OTRA VEZ.... \n");
        return;
    }
    printf("\nPresiona Enter para continuar...\n");
    getchar();
}

void ConcatenarCadenas(CADENAS_LIST *datos) {
    int len1 = calcular_longitud_cadena(datos->cadena1);
    int len2 = calcular_longitud_cadena(datos->cadena2);
    
    // Asignamos memoria dinámica exacta para la suma de ambas cadenas
    char* cadenaNueva = (char*)malloc((len1 + len2 + 1) * sizeof(char)); 
    
    copiar_cadena(cadenaNueva, datos->cadena1);
    pegar_cadena(cadenaNueva, datos->cadena2);

    system("clear");
    concatenar();
    
    printf("\nLa concatenacion de las cadenas es: %s\n", cadenaNueva);
    printf("La longitud de la cadena concatenada es: %d\n", calcular_longitud_cadena(cadenaNueva));
    printf("\nPresiona Enter para continuar...\n");
    getchar();
    
    GuardarResultado(datos, cadenaNueva);
    
    // Liberamos la memoria temporal
    free(cadenaNueva);
}


void PotenciaCadenas(CADENAS_LIST *datos){
    system("clear");
    poten();
    printf("\nEstas son las cadenas actuales:\n");
    printf("Cadena 1: %s\n", datos->cadena1);
    printf("Cadena 2: %s\n", datos->cadena2);
    printf("Cual de las dos cadenas deseas potenciar? (1 o 2): ");
    int seleccion;
    scanf("%d", &seleccion);
    while (getchar() != '\n');
    
    char* cadenaBase;
    if (seleccion == 1) cadenaBase = datos->cadena1;
    else if (seleccion == 2) cadenaBase = datos->cadena2;
    else {
        printf("Opcion no valida.\n");
        return;
    }
    

    printf("Ingrese la potencia a la que desea elevar la cadena (EJ: 2 o -2): \n");
    printf("NOTA: Al ser la potencia negativa, se generara la cadena invertida elevada a la potencia\n");
    int k;
    scanf("%d", &k);
    while (getchar() != '\n');

    int lenBase = calcular_longitud_cadena(cadenaBase);

    if (k > 0) {
        // Tamaño exacto: Longitud de la base multiplicada por la potencia k
        char* cadenaPotencia = (char*)malloc((lenBase * k + 1) * sizeof(char));
        cadenaPotencia[0] = '\0'; // Inicializar como cadena vacía

        for (int i = 0; i < k; i++){
            pegar_cadena(cadenaPotencia, cadenaBase);
        }
        printf("\nLa potencia positiva es: %s\n", cadenaPotencia);
        GuardarResultado(datos, cadenaPotencia);
        free(cadenaPotencia);

    } else if (k < 0) {
        int absK = -k;
        char* cadenaPotencia = (char*)malloc((lenBase * absK + 1) * sizeof(char));
        cadenaPotencia[0] = '\0';
        
        // Memoria para la invertida
        char* invertida = (char*)malloc((lenBase + 1) * sizeof(char));
        for (int i = 0; i < lenBase; i++) {
            invertida[i] = cadenaBase[lenBase - 1 - i];
        }
        invertida[lenBase] = '\0';

        for (int i = 0; i < absK; i++){
            pegar_cadena(cadenaPotencia, invertida);
        }
        printf("\nLa potencia negativa es: %s\n", cadenaPotencia);
        printf("\nPresiona Enter para continuar...\n");
        getchar();
        GuardarResultado(datos, cadenaPotencia);
        
        free(invertida);
        free(cadenaPotencia);

    } else {
        printf("La potencia de una cadena a la 0 es la cadena vacia.\n");
        printf("\nPresiona Enter para continuar...\n");
        getchar();
        GuardarResultado(datos, ""); 
    }
}

void LongitudCadenas(CADENAS_LIST *datos){
    system("clear");
    longit();
    printf("\nLa longitud de la cadena 1 es: %d\n", calcular_longitud_cadena(datos->cadena1));
    printf("La longitud de la cadena 2 es: %d\n", calcular_longitud_cadena(datos->cadena2));

    printf("\nPresiona Enter para continuar...\n");
    getchar();
}

void PrefijosSufijos(CADENAS_LIST *datos){
    system("clear");
    prefig();
    printf("\nDe que cadena desea obtener los prefijos y sufijos? (1 o 2): ");
    int opcion;
    scanf("%d", &opcion);
    while (getchar() != '\n');
    
    char* cadenaBase;
    if (opcion == 1) cadenaBase = datos->cadena1;
    else if (opcion == 2) cadenaBase = datos->cadena2;
    else {
        printf("Opcion no valida.\n");
        return;
    }

    int len = calcular_longitud_cadena(cadenaBase);
    // Asignamos memoria dinámica para el arreglo temporal
    char* temp = (char*)malloc((len + 1) * sizeof(char));

    printf("Los prefijos son: \n");
    for (int i = 0; i <= len; i++) {
        copiar_cantidad_cadena(temp, cadenaBase, i);
        temp[i] = '\0';
        if(calcular_longitud_cadena(temp) == 0) printf("(vacia)\n");
        else printf("%s\n", temp);
    }

    printf("Los sufijos son: \n");
    for (int i = 0; i <= len; i++) {
        copiar_cantidad_cadena(temp, cadenaBase + i, len - i);
        temp[len - i] = '\0';
        if(calcular_longitud_cadena(temp) == 0) printf("(vacia)\n");
        else printf("%s\n", temp);
    }
    
    free(temp);

    printf("\nPresiona Enter para continuar...\n");
    getchar();
}


void Subcadenas(CADENAS_LIST *datos){
    system("clear");
    subc();

    int len1 = calcular_longitud_cadena(datos->cadena1);
    char* temp = (char*)malloc((len1 > calcular_longitud_cadena(datos->cadena2) ? len1 : calcular_longitud_cadena(datos->cadena2)) + 1);

    printf("\nLas subcadenas de la cadena 1 son: \n");
    for (int i = 0; i < len1; i++) {
        for (int j = i; j < len1; j++) {
            copiar_cantidad_cadena(temp, datos->cadena1 + i, j - i + 1);
            temp[j - i + 1] = '\0';
            printf("%s\n", temp);
        }
    }
    
    int len2 = calcular_longitud_cadena(datos->cadena2);
    printf("\nLas subcadenas de la cadena 2 son: \n");
    for (int i = 0; i < len2; i++) {
        for (int j = i; j < len2; j++) {
            copiar_cantidad_cadena(temp, datos->cadena2 + i, j - i + 1);
            temp[j - i + 1] = '\0';
            printf("%s\n", temp);
        }
    }
    free(temp);

    printf("\nPresiona Enter para continuar...\n");
    getchar();
}

void Subsecuencias(CADENAS_LIST *datos){
    system("clear");
    subcsec();

    int len1 = calcular_longitud_cadena(datos->cadena1);
    if (len1 > 12) {
        printf("\nError: La cadena 1 tiene mas de 12 caracteres: (%d). \nOperacion cancelada.\n", len1);
    } else {
        char* temp = (char*)malloc((len1 + 1) * sizeof(char));
        printf("\nLas subsecuencias de la cadena 1 son: \n");
        for (int i = 0; i < (1 << len1); i++) {
            int index = 0;
            for (int j = 0; j < len1; j++) {
                if (i & (1 << j)) {
                    temp[index++] = datos->cadena1[j];
                }
            }
            temp[index] = '\0';
            if(calcular_longitud_cadena(temp) == 0) printf("(vacia)\n");
            else printf("%s\n", temp);
        }
        free(temp);
    }

    int len2 = calcular_longitud_cadena(datos->cadena2);
    if (len2 > 12) {
        printf("\nError: La cadena 2 tiene mas de 12 caracteres (%d). Operacion cancelada.\n", len2);
    } else {
        char* temp2 = (char*)malloc((len2 + 1) * sizeof(char));
        printf("\nLas subsecuencias de la cadena 2 son: \n");
        for (int i = 0; i < (1 << len2); i++) {
            int index = 0;
            for (int j = 0; j < len2; j++) {
                if (i & (1 << j)) {
                    temp2[index++] = datos->cadena2[j];
                }
            }
            temp2[index] = '\0';
            if(calcular_longitud_cadena(temp2) == 0) printf("(vacia)\n");
            else printf("%s\n", temp2);
        }
        free(temp2);
    }
    printf("\nPresiona Enter para continuar...\n");
    getchar();
}

//=======================================

//=======================================
//MENU

void Menu(CADENAS_LIST *datos) {
    int ab;
    do {

        system("clear");
        menu();
        printf("\n========================================\n");
        printf("ESTADO ACTUAL:\n");
        printf("Cadena 1: %s\n", datos->cadena1);
        printf("Cadena 2: %s\n", datos->cadena2);
        printf("========================================\n");
        printf("\nQue operacion deseas realizar?\n");
        printf("1.- Concatenar cadenas\n");
        printf("2.- Potencia de cadenas (positiva y negativa)\n");
        printf("3.- Calculo de longitud de cadenas.\n");
        printf("4.- Generacion de prefijos y sufijos de una cadena.\n");
        printf("5.- Generacion de subcadenas.\n");
        printf("6.- Generacion de subsecuencias.\n");
        printf("7.- Salir del programa\n");
        printf("Opción: ");
        scanf("%d", &ab);
        while (getchar() != '\n');

        switch (ab) {
            case 1: ConcatenarCadenas(datos); break;
            case 2: PotenciaCadenas(datos); break;
            case 3: LongitudCadenas(datos); break;
            case 4: PrefijosSufijos(datos); break;
            case 5: Subcadenas(datos); break;
            case 6: Subsecuencias(datos); break;
            case 7: system("clear"); sal(); break;
            default: printf("Opcion no valida.\n"); break;
        }
    } while (ab != 7);
} 

//=======================================