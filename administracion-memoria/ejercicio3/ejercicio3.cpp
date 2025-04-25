/*
Implementar un programa para almacenar valores enteros en una secuencia de
punteros. Se requiere funciones o procedimientos que permitan insertar los
elementos al principio de la secuencia y al final
*/

#include <iostream>

using namespace std;

struct Nodo
{
  int n;
  Nodo *siguiente;
};

void insertarInicio(Nodo *&ptr_primero, int n)
{
  // Nodo nodo = {n, ptr_primero}; Se destruye al salir
  Nodo *nodo = new Nodo{n, ptr_primero};
  ptr_primero = nodo;
}

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

int main()
{
  int n = 10;
  Nodo *primero = new Nodo{n, nullptr};
  insertarInicio(primero, 100);
  insertarInicio(primero, 300);
  insertarFinal(primero, 50);
  insertarInicio(primero, 300);
  insertarFinal(primero, 50);
  insertarInicio(primero, 300);
  recorrerLista(primero);
  return 0;
}
