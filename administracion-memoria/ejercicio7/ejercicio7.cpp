/*
Implementar una función iterativa para buscar un elemento en un conjunto ordenado
sin repetidos con arreglo y con secuencia de nodo. No usar búsqueda binaria.
*/

#include <iostream>

using namespace std;

struct Nodo
{
  int n;
  Nodo *siguiente;
};

void insertarOrdenadoSinRepetirArreglo(int *arr, int &size, int num)
{
  int i = 0;

  while (i < size && arr[i] < num)
  {
    i++;
  }
  if (i < size && arr[i] == num)
    return;

  for (int j = size; j > i; j--)
  {
    arr[j] = arr[j - 1];
  }

  arr[i] = num;
  size++;
}

void insertarOrdenadoSinRepetirLista(Nodo *&primero, int dato)
{
  if (primero == nullptr || dato < primero->n)
  {
    if (primero != nullptr && primero->n == dato)
      return;

    Nodo *nuevo = new Nodo{dato, primero};
    primero = nuevo;
    return;
  }

  Nodo *actual = primero;
  while (actual->siguiente != nullptr && actual->siguiente->n < dato)
  {
    actual = actual->siguiente;
  }

  if (actual->siguiente != nullptr && actual->siguiente->n == dato)
    return;

  Nodo *nuevo = new Nodo{dato, actual->siguiente};
  actual->siguiente = nuevo;
}

void mostrarArreglo(int *arreglo, int MAX)
{
  cout << "Arreglo: " << endl;
  for (int i = 0; i < MAX; i++)
  {
    cout << arreglo[i] << " ";
  }

  cout << endl;
}

void mostrarLista(Nodo *primero)
{
  cout << "Lista: " << endl;
  Nodo *actual = primero;

  while (actual != nullptr)
  {
    cout << actual->n << " ";
    actual = actual->siguiente;
  }

  cout << endl;
}

int buscarEnArreglo(int *arreglo, int numero, int MAX)
{
  for (int i = 0; i < MAX; i++)
  {
    if (arreglo[i] == numero)
      return i;
  }
  return -1;
}

Nodo *buscarEnLista(Nodo *primero, int numero)
{
  Nodo *actual = primero;
  while (actual != nullptr)
  {
    if (actual->n == numero)
      return actual;
    actual = actual->siguiente;
  }
  return nullptr;
}

int main()
{
  int MAX;
  cout << "Ingrese cantidad de elementos: ";
  cin >> MAX;
  // inicializacion del arreglo
  int arreglo[MAX] = {};

  Nodo *primero = nullptr;

  int cantidadActual = 0;

  for (int i = 0; i < MAX; i++)
  {
    int num;
    cin >> num;
    insertarOrdenadoSinRepetirArreglo(arreglo, cantidadActual, num);
    insertarOrdenadoSinRepetirLista(primero, num);
  }
  int n1 = buscarEnArreglo(arreglo, 5, MAX);
  Nodo *p1 = buscarEnLista(primero, 5);
  mostrarArreglo(arreglo, MAX);
  mostrarLista(primero);
  cout << p1->n << endl;
  return 0;
}