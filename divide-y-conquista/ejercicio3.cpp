/*
Se tiene un arreglo T de n enteros distintos, ordenado en forma creciente. Dado un rango definido
por dos valores enteros x e y, con la condición de que x ≤ y, se requiere implementar un algoritmo
en C++ que determine cuántos elementos del arreglo T se encuentran comprendidos entre x e y,
inclusive. La complejidad temporal de su algoritmo debe pertenecer a O(log n).
*/

#include <iostream>
using namespace std;

int MAX = 6;

int encontrarIndiceElemento(int arr[], int inicio, int fin, int elemento)
{
  if (inicio > fin)
  {
    return -1;
  }

  int p = (fin - inicio) / 2 + inicio;

  if (arr[p] == elemento)
  {
    return p;
  }
  else if (arr[p] > elemento)
  {
    return encontrarIndiceElemento(arr, inicio, p - 1, elemento);
  }
  else if (arr[p] < elemento)
  {
    return encontrarIndiceElemento(arr, p + 1, fin, elemento);
  }
}

int cantidadElementos(int arr[], int x, int y)
{
  if (x > y)
  {
    cout << "x debe ser menor o igual a y";
    return -1;
  }

  int elementoX = encontrarIndiceElemento(arr, 0, MAX - 1, x);
  int elementoY = encontrarIndiceElemento(arr, 0, MAX - 1, y);

  if (elementoX == -1 || elementoY == -1)
  {
    return -1;
  }

  return (elementoY - elementoX + 1);
}
int main()
{
  int arr[] = {-3, -2, -1, 0, 1, 5};
  int cantidad = cantidadElementos(arr, -3, 0);
  cout << cantidad << endl;
  return 0;
}