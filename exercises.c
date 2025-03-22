#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();
  for (int i = 1; i <= 10; i++) {
      int *dato = (int *) malloc(sizeof(int));
      *dato = i;
      pushBack(L, dato);
    }
    return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) { 
  int suma = 0;
  int talla = get_size(L);
  int *dato = (int*) first(L);
  for (int i = 0; i < talla; i++) {
    suma += *dato;
    dato = (int*) next(L);
  }
  return suma; 
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
  int talla = get_size(L);
  int *dato = (int*) first(L);
  for (int i = 0; i < talla; i++) {
    if (*dato == elem) {
      popCurrent(L);
    }
    dato = (int*) next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {
  Stack *Paux = create_stack();

  while (top(P1) != NULL) {
    push(Paux, pop(P1));
  }

  while (top(Paux) != NULL) {
    push(P1, top(Paux));
    push(P2, pop(Paux));
  } 
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  Stack *pila = create_stack();

  char *c = cadena;
  while (*c) {
    if (*c == '(' || *c == '{' || *c == '[') {
      push(pila, c);
    }
    else if (*c == ')' || *c == '}' || *c == ']') {
      if (get_size(pila) == 0) return 0;
    
    char *topito = pop(pila);
    if (*c == ')' && *topito != '(' || *c == '}' && *topito != '{' || *c == ']' && *topito != '[') return 0;
    
    }
    c++;
  }
  return (get_size(pila) == 0) ? 1 : 0;
}
  

