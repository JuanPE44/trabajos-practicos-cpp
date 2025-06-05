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

int mediana(int a1[], int inicio1, int fin1, int a2[], int inicio2, int fin2)
{
  // Dos elementos
  if (fin1 == inicio1 + 1)
  {
    if (a1[fin1 - 1] < a2[inicio2])
    {
      return a1[fin1 - 1];
    }
    else if (a2[fin2 - 1] < a1[inicio1])
    {
      return a2[fin2 - 1];
    }
    else
    {
      return max(a1[inicio1], a2[inicio2]);
    }
  }

  // Un solo elemento
  if (inicio1 == fin1)
  {
    if (a1[inicio1] < a2[inicio2])
    {
      return min(a1[inicio1], a2[inicio2]);
    }
    else
    {
      return min(a2[inicio2], a1[inicio1]);
    }
  }

  int med = (fin1 + inicio1) / 2;

  if (a1[med] == a2[med])
  {
    return a1[med];
  }
  else if (a1[med] < a2[med])
  {
    return mediana(a1, inicio1, med - 1, a2, inicio2, med - 1);
  }
  else
  {
    return mediana(a1, med + 1, fin1, a2, med + 1, fin2);
  }
}

int main()
{
  int a1[] = {1, 3, 5, 7};
  int a2[] = {2, 4, 6, 8};

  int n = sizeof(a1) / sizeof(a1[0]);
  int median = mediana(a1, 0, n - 1, a2, 0, n - 1);
  cout << "La mediana es: " << median << endl;

  return 0;
}
