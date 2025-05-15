/*
Tu plataforma de e-commerce administra un arreglo ordenado S que contiene n cupones,
representados por valores monetarios enteros y distintos. Dado un valor entero x (que representa
un precio objetivo de compra), se desea determinar si existe al menos un par de cupones en el
arreglo cuya suma sea exactamente igual a x
a) Implementar un algoritmo en C++ que permita determinar si existe dicho par de cupones.
b) Calcule la complejidad temporal.
*/

#include <iostream>
using namespace std;

int contieneCupones(int arr[], int i, int j, int x)
{
  if (arr[i] + arr[j] == x)
  {
    return true;
  }
  if (i == j)
  {
    return false;
  }
  if (arr[i] + arr[j] < x)
  {
    return contieneCupones(arr, i + 1, j, x);
  }
  return contieneCupones(arr, i, j - 1, x);
}
// Complejidad temporal: O(n)

int main()
{
  int arr[] = {1, 5, 8, 10, 14, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 15;
  bool encontrado = contieneCupones(arr, 0, n - 1, x);
  if (encontrado)
  {
    cout << "Si existe un par de cupones con suma " << x << endl;
  }
  else
  {
    cout << "No existe un par de cupones con suma " << x << endl;
  }
  return 0;
}