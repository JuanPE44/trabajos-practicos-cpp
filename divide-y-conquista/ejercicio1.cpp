/*
Implemente en C++ los métodos de ordenamiento mergesort y quicksort de forma tal que, dado
un arreglo de elementos comparables, ordenen sus elementos ascendentemente.
*/

#include <iostream>
using namespace std;

void intercambiar(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Partición usando el último elemento como pivote
int particionar(int arr[], int inicio, int fin)
{
  int pivote = arr[fin]; // pivote
  int i = inicio - 1;    // índice del menor elemento

  for (int j = inicio; j < fin; j++)
  {
    if (arr[j] <= pivote)
    {
      i++;
      intercambiar(arr[i], arr[j]);
    }
  }

  intercambiar(arr[i + 1], arr[fin]);
  return i + 1;
}

// Función principal de Quicksort
void quicksort(int arr[], int inicio, int fin)
{
  if (inicio < fin)
  {
    int indicePivote = particionar(arr, inicio, fin);
    quicksort(arr, inicio, indicePivote - 1);
    quicksort(arr, indicePivote + 1, fin);
  }
}

// Función para fusionar dos mitades ordenadas
void merge(int arr[], int inicio, int medio, int fin)
{
  int n1 = medio - inicio + 1;
  int n2 = fin - medio;

  // Crear arreglos temporales
  int izquierda[n1], derecha[n2];

  // Copiar los datos a los arreglos temporales
  for (int i = 0; i < n1; i++)
    izquierda[i] = arr[inicio + i];
  for (int j = 0; j < n2; j++)
    derecha[j] = arr[medio + 1 + j];

  // Fusionar los arreglos temporales en arr[]
  int i = 0, j = 0, k = inicio;
  while (i < n1 && j < n2)
  {
    if (izquierda[i] <= derecha[j])
    {
      arr[k] = izquierda[i];
      i++;
    }
    else
    {
      arr[k] = derecha[j];
      j++;
    }
    k++;
  }

  // Copiar los elementos restantes
  while (i < n1)
  {
    arr[k] = izquierda[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = derecha[j];
    j++;
    k++;
  }
}

// MergeSort recursivo
void mergeSort(int arr[], int inicio, int fin)
{
  if (inicio < fin)
  {
    int medio = inicio + (fin - inicio) / 2;
    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio + 1, fin);
    merge(arr, inicio, medio, fin);
  }
}

// Función para imprimir el arreglo
void imprimir(int arr[], int tam)
{
  for (int i = 0; i < tam; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int MAX = 6;
  int array1[] = {10, 2, 4, 3, 20, 7};
  int array2[] = {20, 10, 2, 3, 4, 7};
  quicksort(array1, 0, MAX - 1);
  mergeSort(array2, 0, MAX - 1);
  imprimir(array1, MAX);
  imprimir(array2, MAX);
  return 0;
}