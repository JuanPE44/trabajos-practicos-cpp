/*
Implementar una función iterativa para hacer una búsqueda binaria para un arreglo
de enteros ordenado.
*/

/*
Implementar una función iterativa para buscar un elemento en un conjunto ordenado
sin repetidos con arreglo y con secuencia de nodo. No usar búsqueda binaria.
*/

#include <iostream>

using namespace std;

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

void mostrarArreglo(int *arreglo, int MAX)
{
  cout << "Arreglo: " << endl;
  for (int i = 0; i < MAX; i++)
  {
    cout << arreglo[i] << " ";
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

int busquedaBinaria(int *arreglo, int MAX, int numero)
{
  int inicio = 0;
  int fin = MAX - 1;
  int medio = MAX / 2;
  while (inicio <= fin)
  {
    if (arreglo[medio] > numero)
    {
      fin = medio + 1;
      medio = inicio + (fin - inicio) / 2;
    }
    else if (arreglo[medio] < numero)
    {
      inicio = medio - 1;
      medio = inicio + (fin - inicio) / 2;
    }
    else
    {
      return medio;
    }
  }
}

int main()
{
  int MAX = 10;
  // cout << "Ingrese cantidad de elementos: ";
  // cin >> MAX;
  //  inicializacion del arreglo
  int arreglo[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int cantidadActual = 0;
  /*
  for (int i = 0; i < MAX; i++)
  {
    int num;
    cin >> num;
    insertarOrdenadoSinRepetirArreglo(arreglo, cantidadActual, num);
  }
    */
  int i = busquedaBinaria(arreglo, MAX, 8);
  mostrarArreglo(arreglo, MAX);
  return 0;
}