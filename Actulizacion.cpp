#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
  int numero;
  struct nodo *sgte;
};

typedef struct nodo *tlista;

void actualizar(tlista &lista, int posicion, int nuevoNumero) {
  
  tlista nodo = lista;
  for (int i = 0; i < posicion; i++) {
    nodo = nodo->sgte;
  }
  nodo->numero = nuevoNumero;
}

void insertar(tlista &lista, int nuevoNumero) {
  
  tlista nuevoNodo = new nodo;
  nuevoNodo->numero = nuevoNumero;
  
  if (lista == NULL) {
    lista = nuevoNodo;
    nuevoNodo->sgte = nuevoNodo;
    return;
  }
  
  tlista ultimoNodo = lista;
  while (ultimoNodo->sgte != lista) {
    ultimoNodo = ultimoNodo->sgte;
  }
  
  ultimoNodo->sgte = nuevoNodo;
  nuevoNodo->sgte = lista;
}
int main() {
  
  tlista lista = NULL;
  insertar(lista, 1);
  insertar(lista, 2);
  insertar(lista, 3);
  
  tlista nodo = lista;
  while (nodo != lista) {
    cout << nodo->numero << " ";
    nodo = nodo->sgte;
  }
  cout << endl;
  int num1, num2;
  cout<<"Numero que quiere actualizar: "<<endl;cin>> num1;
  cout<<"Numero por el que los quiere cambiar: "<<endl;cin>> num2;
  actualizar(lista, num1, num2);
  
  nodo = lista;
  while (nodo != lista) {
    cout << nodo->numero << " ";
    nodo = nodo->sgte;
  }
  cout << endl;
  return 0;
}
