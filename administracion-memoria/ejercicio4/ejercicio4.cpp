/*
Implementar un programa que elimine un nodo de una secuencia.
*/

#include <iostream>

using namespace std;

struct Nodo
{
  int n;
  Nodo *siguiente;
};

void eliminarNodo(Nodo *&primero, int dato)
{
  Nodo *actual = primero;
  Nodo *anterior = nullptr;

  while (actual != nullptr && actual->n != dato)
  {
    anterior = actual;
    actual = actual->siguiente;
  }

  if (actual == nullptr)
  {
    cout << ("el dato no esta en la lista") << endl;
  }
  else
  {
    if (actual == primero)
    {
      primero = actual->siguiente;
    }
    else
    {
      anterior->siguiente = actual->siguiente;
    }
  }
}
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
  insertarInicio(primero, 200);
  insertarFinal(primero, 300);
  eliminarNodo(primero, 300);
  recorrerLista(primero);
  return 0;
}
