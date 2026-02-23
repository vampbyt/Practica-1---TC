#include <stdio.h>
#include <stdlib.h>

// 1. La estructura ahora usa punteros dinámicos
typedef struct {
    char* cadena1;
    char* cadena2;
} MisCadenas;

// ========================================================
// FUNCIONES MANUALES DE CADENAS
// ========================================================

int MiLongitud(const char* cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}

void MiCopiar(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; 
}

void MiCopiarN(char* destino, const char* origen, int n) {
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

void MiPegar(char* destino, const char* origen) {
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

// ========================================================

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

void GuardarResultado(MisCadenas *datos, const char *resultado) {
    int opcion;
    printf("\n¿Desea guardar este resultado para operar posteriormente?\n");
    printf("1.- Guardar en Cadena 1\n");
    printf("2.- Guardar en Cadena 2\n");
    printf("0.- No guardar\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    int len = MiLongitud(resultado);

    if (opcion == 1) {
        // realloc ajusta la memoria de cadena1 al nuevo tamaño exacto
        datos->cadena1 = (char*)realloc(datos->cadena1, (len + 1) * sizeof(char));
        MiCopiar(datos->cadena1, resultado);
        printf("¡Cadena 1 actualizada exitosamente!\n");
    } else if (opcion == 2) {
        datos->cadena2 = (char*)realloc(datos->cadena2, (len + 1) * sizeof(char));
        MiCopiar(datos->cadena2, resultado);
        printf("¡Cadena 2 actualizada exitosamente!\n");
    }
}

void ConcatenarCadenas(MisCadenas *datos) {
    int len1 = MiLongitud(datos->cadena1);
    int len2 = MiLongitud(datos->cadena2);
    
    // Asignamos memoria dinámica exacta para la suma de ambas cadenas
    char* cadenaNueva = (char*)malloc((len1 + len2 + 1) * sizeof(char)); 
    
    MiCopiar(cadenaNueva, datos->cadena1);
    MiPegar(cadenaNueva, datos->cadena2);
    
    printf("\nLa concatenación de las cadenas es: %s\n", cadenaNueva);
    printf("La longitud de la cadena concatenada es: %d\n", MiLongitud(cadenaNueva));
    
    GuardarResultado(datos, cadenaNueva);
    
    // Liberamos la memoria temporal
    free(cadenaNueva);
}

void PotenciaCadenas(MisCadenas *datos){
    printf("\nEstas son las cadenas actuales:\n");
    printf("Cadena 1: %s\n", datos->cadena1);
    printf("Cadena 2: %s\n", datos->cadena2);
    printf("¿Cuál de las dos cadenas desea potenciar? (1 o 2): ");
    int seleccion;
    scanf("%d", &seleccion);
    
    char* cadenaBase;
    if (seleccion == 1) cadenaBase = datos->cadena1;
    else if (seleccion == 2) cadenaBase = datos->cadena2;
    else {
        printf("Opción no válida.\n");
        return;
    }

    printf("Ingrese la potencia a la que desea elevar la cadena (+ o -): ");
    int k;
    scanf("%d", &k);

    int lenBase = MiLongitud(cadenaBase);

    if (k > 0) {
        // Tamaño exacto: Longitud de la base multiplicada por la potencia k
        char* cadenaPotencia = (char*)malloc((lenBase * k + 1) * sizeof(char));
        cadenaPotencia[0] = '\0'; // Inicializar como cadena vacía

        for (int i = 0; i < k; i++){
            MiPegar(cadenaPotencia, cadenaBase);
        }
        printf("La potencia positiva es: %s\n", cadenaPotencia);
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
            MiPegar(cadenaPotencia, invertida);
        }
        printf("La potencia negativa es: %s\n", cadenaPotencia);
        GuardarResultado(datos, cadenaPotencia);
        
        free(invertida);
        free(cadenaPotencia);

    } else {
        printf("La potencia de una cadena a la 0 es la cadena vacía (Epsilon).\n");
        GuardarResultado(datos, ""); 
    }
}

void LongitudCadenas(MisCadenas *datos){
    printf("\nLa longitud de la cadena 1 es: %d\n", MiLongitud(datos->cadena1));
    printf("La longitud de la cadena 2 es: %d\n", MiLongitud(datos->cadena2));
}

void PrefijosSufijos(MisCadenas *datos){
    printf("\n¿De qué cadena desea obtener los prefijos y sufijos? (1 o 2): ");
    int opcion;
    scanf("%d", &opcion);
    
    char* cadenaBase;
    if (opcion == 1) cadenaBase = datos->cadena1;
    else if (opcion == 2) cadenaBase = datos->cadena2;
    else {
        printf("Opción no válida.\n");
        return;
    }

    int len = MiLongitud(cadenaBase);
    // Asignamos memoria dinámica para el arreglo temporal
    char* temp = (char*)malloc((len + 1) * sizeof(char));

    printf("Los prefijos son: \n");
    for (int i = 0; i <= len; i++) {
        MiCopiarN(temp, cadenaBase, i);
        temp[i] = '\0';
        if(MiLongitud(temp) == 0) printf("(vacía)\n");
        else printf("%s\n", temp);
    }

    printf("Los sufijos son: \n");
    for (int i = 0; i <= len; i++) {
        MiCopiarN(temp, cadenaBase + i, len - i);
        temp[len - i] = '\0';
        if(MiLongitud(temp) == 0) printf("(vacía)\n");
        else printf("%s\n", temp);
    }
    
    free(temp);
}

void Subcadenas(MisCadenas *datos){
    int len1 = MiLongitud(datos->cadena1);
    char* temp = (char*)malloc((len1 > MiLongitud(datos->cadena2) ? len1 : MiLongitud(datos->cadena2)) + 1);

    printf("\nLas subcadenas de la cadena 1 son: \n");
    for (int i = 0; i < len1; i++) {
        for (int j = i; j < len1; j++) {
            MiCopiarN(temp, datos->cadena1 + i, j - i + 1);
            temp[j - i + 1] = '\0';
            printf("%s\n", temp);
        }
    }
    
    int len2 = MiLongitud(datos->cadena2);
    printf("\nLas subcadenas de la cadena 2 son: \n");
    for (int i = 0; i < len2; i++) {
        for (int j = i; j < len2; j++) {
            MiCopiarN(temp, datos->cadena2 + i, j - i + 1);
            temp[j - i + 1] = '\0';
            printf("%s\n", temp);
        }
    }
    free(temp);
}

void Subsecuencias(MisCadenas *datos){
    int len1 = MiLongitud(datos->cadena1);
    if (len1 > 12) {
        printf("\nError: La cadena 1 tiene más de 12 caracteres (%d). Operación cancelada.\n", len1);
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
            if(MiLongitud(temp) == 0) printf("(vacía)\n");
            else printf("%s\n", temp);
        }
        free(temp);
    }

    int len2 = MiLongitud(datos->cadena2);
    if (len2 > 12) {
        printf("\nError: La cadena 2 tiene más de 12 caracteres (%d). Operación cancelada.\n", len2);
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
            if(MiLongitud(temp2) == 0) printf("(vacía)\n");
            else printf("%s\n", temp2);
        }
        free(temp2);
    }
}

void Menu(MisCadenas *datos) {
    int ab;
    do {
        printf("\n========================================\n");
        printf("ESTADO ACTUAL:\n");
        printf("Cadena 1: %s\n", datos->cadena1);
        printf("Cadena 2: %s\n", datos->cadena2);
        printf("========================================\n");
        printf("¿Qué operación desea realizar?\n");
        printf("1.- Concatenar cadenas\n");
        printf("2.- Potencia de cadenas (positiva y negativa)\n");
        printf("3.- Calculo de longitud de cadenas.\n");
        printf("4.- Generación de prefijos y sufijos de una cadena.\n");
        printf("5.- Generación de subcadenas.\n");
        printf("6.- Generación de subsecuencias.\n");
        printf("7.- Salir del programa\n");
        printf("Opción: ");
        scanf("%d", &ab);

        switch (ab) {
            case 1: ConcatenarCadenas(datos); break;
            case 2: PotenciaCadenas(datos); break;
            case 3: LongitudCadenas(datos); break;
            case 4: PrefijosSufijos(datos); break;
            case 5: Subcadenas(datos); break;
            case 6: Subsecuencias(datos); break;
            case 7: printf("Saliendo del menú...\n"); break;
            default: printf("Opción no válida.\n"); break;
        }
    } while (ab != 7);
} 

int main (){
    MisCadenas misDatos;
    
    // Inicializamos las cadenas apuntando a NULL para que realloc sepa que es la primera vez
    misDatos.cadena1 = NULL;
    misDatos.cadena2 = NULL;
    
    char bufferEntrada[200]; 
    int entradasValidas = 0;

    printf("Hola, bienvenido al menú de procesamiento de cadenas.\n");

    while(!entradasValidas) {
        printf("\nIngrese su cadena 1 (alfanumérica, max 49 chars): ");
        scanf("%s", bufferEntrada);
        
        int len1 = MiLongitud(bufferEntrada);

        if (len1 >= 50) {
            printf("Error: Las cadenas deben ser menores a 50 caracteres.\n");
            continue; 
        } else if (!esAlfanumerica(bufferEntrada)) {
            printf("Error: El alfabeto solo permite letras y números (sin simbolos especiales).\n");
            continue;
        }
        
        // Asignamos memoria dinámica exacta a cadena1 usando la información validada
        misDatos.cadena1 = (char*)malloc((len1 + 1) * sizeof(char));
        MiCopiar(misDatos.cadena1, bufferEntrada);

        printf("Ingrese su cadena 2 (alfanumérica, max 49 chars): ");
        scanf("%s", bufferEntrada);
        
        int len2 = MiLongitud(bufferEntrada);

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
        MiCopiar(misDatos.cadena2, bufferEntrada);
        
        entradasValidas = 1; 
    }

    Menu(&misDatos);

    // Al final del programa, regresamos toda la memoria usada al sistema
    free(misDatos.cadena1);
    free(misDatos.cadena2);

    return 0;
}