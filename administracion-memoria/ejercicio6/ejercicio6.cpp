/*
Cargar un conjunto de N enteros manteniéndolo ordenado y al finalizar mostrar el
arreglo por consola. Los elementos del conjunto no se deben repetir. Los valores son
ingresados como argumento del programa.
a. Implementar para arreglo de N elementos.
b. Implementar para una secuencia de punteros.
Realizar el seguimiento para la entrada {1, 9, 4, -1, 9}. Salida esperada {-1,
1, 4, 9}
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
    cout << arreglo[i] << endl;
  }
}

void recorrerLista(Nodo *primero)
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

  mostrarArreglo(arreglo, MAX);
  recorrerLista(primero);
  return 0;
}

/* metodo inserccion
void ordenarArreglo(int *arr, int MAX)
{
  int aux, j;
  for (int i = 1; i < MAX; i++)
  {
    aux = arr[i];
    j = i - 1;
    while ((j >= 0) && (arr[j] > aux))
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = aux;
  }
}
*/