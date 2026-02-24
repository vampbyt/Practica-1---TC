#include <stdio.h>
#include <stdlib.h>


//Funciones de texto, para cosas visuales y menus, donde se llama a la funcion y demás
void presen() {
    printf("\033[44m======================================================================================\033[0m\n");
    printf("                                                       ");             printf("\033[32m          __\n");
    printf("\033[97m                Bienvenido a la practica 1             ");     printf("\033[93m       <");printf("\033[32m(o )___\n");
    printf("\033[97m                    Alfabetos y cadenas                ");              printf("\033[32m        (    "); printf("\033[0m__");printf("\033[32m)\n");
    printf("                                                       ");             printf("\033[93m          `----'\n");
    printf("\033[44m======================================================================================\033[0m\n");
    printf("\033[97m By: Ceron Samperio Lizeth Montserrat\033[0m\n");
    printf("\033[97m By: Higuera Pineda Angel Abraham\033[0m\n");
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("INFO: \n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n");
}


void sal(){
    system("cls");
    printf("\033[44m======================================================================================\033[0m\n");
    printf("\033[33m                         Saliendo... \033[94m Gracias por estar aqui                            \033[0m\n");
    printf("\033[44m======================================================================================\033[0m\n");
    printf("\n");
}


void guardando(){
    system("cls");
    printf("\033[44m======================================================================================\033[0m\n");
    printf("\033[33m                         GUARDANDO... \033[94m CADENAS...                             \033[0m\n");
    printf("\033[44m======================================================================================\033[0m\n");
    printf("\n");
}