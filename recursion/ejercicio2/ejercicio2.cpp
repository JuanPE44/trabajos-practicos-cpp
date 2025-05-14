/*
Dada una lista vinculada, implemente una función recursiva que calcule el número
de ocurrencias de un elemento dado.
*/
#include <iostream>

using namespace std;

struct Nodo
{
  int n;
  Nodo *siguiente;
};

void insertarFinal(Nodo *&actual, int valor)
{
  Nodo *nuevoNodo = new Nodo{valor, nullptr};

  if (actual == nullptr)
  {
    actual = nuevoNodo;
  }
  else
  {
    Nodo *temp = actual;
    while (temp->siguiente != nullptr)
    {
      temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
  }
}

void recorrerLista(Nodo *primero)
{
  Nodo *actual = primero;

  while (actual != nullptr)
  {
    cout << actual->n << " ";
    actual = actual->siguiente;
  }

  cout << endl;
}

int obtenerOcurrencias(Nodo *actual, int dato)
{
  if (actual == nullptr)
  {
    return 0;
  }
  else if (actual->n == dato)
  {
    return 1 + obtenerOcurrencias(actual->siguiente, dato);
  }
  else
  {
    return obtenerOcurrencias(actual->siguiente, dato);
  }
}

int main()
{
  int n = 10;
  Nodo *primero = new Nodo{n, nullptr};
  insertarFinal(primero, 100);
  insertarFinal(primero, 200);
  insertarFinal(primero, 300);
  insertarFinal(primero, 20);
  insertarFinal(primero, 300);
  recorrerLista(primero);
  int obtenidas = obtenerOcurrencias(primero, 20);
  return 0;
}
