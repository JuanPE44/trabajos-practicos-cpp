/*
2) Sea T un arreglo ordenado de n enteros diferentes (puede incluir números negativos):
a) Implemente un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T [i] = i, siempre
y cuando exista tal índice. La complejidad temporal de la solución propuesta debe pertenecer
a O(log n).
b) Explicar por qué una búsqueda binaria es esencial en grandes volúmenes de datos (nube, redes
sociales, etc.)
*/

#include <iostream>
using namespace std;

int encontrarIndice(int arr[], int inicio, int fin)
{
  if (inicio > fin)
  {
    return -1;
  }

  int p = (fin - inicio) / 2 + inicio;

  if (arr[p] == p)
  {
    return p;
  }
  else if (arr[p] > p)
  {
    return encontrarIndice(arr, inicio, p - 1);
  }
  else if (arr[p] < p)
  {
    return encontrarIndice(arr, p + 1, fin);
  }
}

int main()
{
  int MAX = 6;
  int arr[] = {-3, -2, -1, 0, 1, 5};
  int i = encontrarIndice(arr, 0, MAX - 1);
  cout << i << endl;
  return 0;
}