/*
En ciertas aplicaciones, puede ser necesario combinar información proveniente de distintas
fuentes sin alterar su estructura original. Supongamos que se tienen dos vectores X e Y, cada uno
con n enteros ordenados en forma creciente. Se desea calcular la mediana del conjunto total de 2n
elementos sin necesidad de mezclar ni ordenar explícitamente los vectores.
Implemente un algoritmo en C++ que resuelva el problema en un tiempo O(log n).
*/

#include <iostream>
#include <algorithm>
using namespace std;
int MAX = 7;

int encontrarMediana(int arr1[], int arr2[], int inicio1, int fin1, int inicio2, int fin2)
{

    if (fin1 - inicio1 == 1 && fin2 - inicio2 == 1)
  {
    return max({arr1[inicio1], arr1[fin1], arr2[inicio2], arr2[fin2]});
  }

  int m1 = (fin1 - inicio1) / 2 + inicio1;
  int m2 = (fin2 - inicio2) / 2 + inicio2;

  if (arr1[m1] > arr2[m2])
  {
    return encontrarMediana(arr1, arr2, inicio1, m1, m2, fin2);
  }
  else
  {
    return encontrarMediana(arr1, arr2, m1, fin1, inicio2, m2);
  }
}

int main()
{
  int arr1[] = {1, 3, 20, 50, 77, 120, 122};
  int arr2[] = {0, 2, 4, 6, 7, 10, 13};
  int i = encontrarMediana(arr1, arr2, 0, MAX - 1, 0, MAX - 1);
  cout << i << endl;
  return 0;
}