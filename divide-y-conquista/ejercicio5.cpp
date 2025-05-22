/*
En aplicaciones de monitoreo (como salud, clima o rendimiento físico), es común analizar
secuencias de datos para identificar comportamientos que alcanzan un pico y luego decrecen, lo
que se conoce como una secuencia unimodal. Formalmente, una secuencia A = (a1, a2,. . . , an) de
longitud n ≥ 3 se llama unimodal si sus elementos primero aumentan y luego disminuyen, es decir
existe un índice p con 1 ≤ p ≤ n tal que a1 < a2 < · · · < ap y ap > ap+1 > · · · > an. Implemente un
algoritmo en C++ que dado un arreglo unidimensional que almacena una secuencia unimodal
encuentre el índice p. La complejidad temporal del algoritmo debe pertenecer a O(log n).
*/
#include <iostream>
using namespace std;

int encontrarPico(int arr[], int inicio, int fin, int MAX)
{
  int mid = inicio + (fin - inicio) / 2;

  if ((mid == 0) || (arr[mid - 1] < arr[mid]) && (mid == MAX - 1) || (arr[mid] > arr[mid + 1]))
  {
    return mid;
  }
  if (mid < MAX - 1 && arr[mid] < arr[mid + 1])
  {
    return encontrarPico(arr, mid + 1, fin, MAX);
  }
  return encontrarPico(arr, inicio, mid - 1, MAX);
}

int main()
{
  int arr[] = {1, 3, 8, 12, 9, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int pico = encontrarPico(arr, 0, n - 1, n); // deberías obtener índice 3
  return 0;
}