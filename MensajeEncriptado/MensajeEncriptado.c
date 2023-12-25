//CHALLENGE_01

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1024

//Lista de struct
typedef struct{
    char *nombre;
    int numero;
}info;

typedef struct node *pos;

struct node {
    info data;
    struct node *next;
};

typedef pos list;

//Funciones de la Lista
bool createNode(pos *p) {
    pos newNode = (pos) malloc(sizeof(struct node));

    if (newNode != NULL) {
        //Inicializamos a NULL todos los elementos del nodo
        newNode->data.nombre = malloc(MAX * sizeof(char));
        newNode->data.numero = 0;
        newNode->next = NULL;

        *p = newNode;

        return true;
    }

    return false;
}

void createEmptyList(list *L) {
    *L = NULL;
}

bool isEmptyList(list L) {
    return L == NULL;
}

void insertList(char *nombre, list *L) {
    pos p = NULL;
    
    if (!createNode(&p)) {
        return;             //Error al crear el nodo
    }

    strcpy(p->data.nombre, nombre);
    p->data.numero=1;
    p->next = NULL;

    if (*L == NULL) {
        *L = p;
    } else {
        pos r;
        for (r = (pos) *L; r->next != NULL; r = r->next);
        r->next = p;
    }
}

void buscarNombre(char *nombre, list *L){
    pos aux = *L;
    while (aux != NULL){
        if(strcmp(aux->data.nombre, nombre)==0){
            aux->data.numero++;
            return;
        }
        aux=aux->next;
    }
    insertList(nombre, L);
}

int trocearCadena(char *cadena, char *trozo[]) // cadena que quieres dividir
{
    int i = 1;
    if ((trozo[0] = strtok(cadena, " \n\t")) == NULL)
        return 0;
    while ((trozo[i] = strtok(NULL, " \n\t")) != NULL) // trozo[] en cada posicion una palabra
        i++;
    return i; // numero de trozos
}


int main(){
    char mensaje[]="murcielago leon jirafa cebra elefante rinoceronte hipopotamo ardilla mapache zorro lobo oso puma jaguar tigre leopardo gato perro caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco tigre jaguar leopardo oso lobo zorro mapache ardilla elefante rinoceronte hipopotamo cebra jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago tucan loro canario colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago flamenco pinguino tucan loro canario colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo leon jirafa murcielago caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo leon jirafa murcielago caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco murcielago leon jirafa cebra elefante rinoceronte hipopotamo ardilla mapache zorro lobo oso puma jaguar tigre leopardo gato perro caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo jirafa leon murcielago pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon paloma colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon paloma colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon";
    char *trozos[MAX];
    int tamano;
    list L;
    createEmptyList(&L);

    tamano=trocearCadena(mensaje, trozos);  //Dividir el mensaje en un array, en cada posicion hay una palabra

    for (int i = 0; i < tamano; i++){       //Buscar cada palabra del mensaje
        buscarNombre(trozos[i], &L);        //Si no esta en la lista lo añade, si esta suma 1 al contador
    }
    
    //Imprimir solucion
    pos aux = L;
    while (aux != NULL){
        printf("%s%d", aux->data.nombre, aux->data.numero);
        aux=aux->next;
    }
    printf("\n");
    
    return 0;
}