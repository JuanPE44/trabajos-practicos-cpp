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

int mediana(int a1[], int mina1, int maxa1, int a2[], int mina2, int maxa2)
{
  if (maxa1 - mina1 > 2)
  { // Caso general
    int med = (maxa1 - mina1) / 2;
    int posa1 = mina1 + med;
    int posa2 = mina2 + med;

    if (a1[posa1] == a2[posa2])
    {
      return a1[posa1];
    }
    else if (a1[posa1] < a2[posa2])
    {
      return mediana(a1, mina1 + med, maxa1, a2, mina2, maxa2 - med);
    }
    else
    {
      return mediana(a1, mina1, maxa1 - med, a2, mina2 + med, maxa2);
    }
  }
  else if (maxa1 - mina1 == 2)
  { // Dos elementos
    if (a1[maxa1 - 1] < a2[mina2])
    {
      return a1[maxa1 - 1];
    }
    else if (a2[maxa2 - 1] < a1[mina1])
    {
      return a2[maxa2 - 1];
    }
    else
    {
      return max(a1[mina1], a2[mina2]);
    }
  }
  else
  { // Un solo elemento
    if (a1[mina1] < a2[mina2])
    {
      return min(a1[mina1], a2[mina2]);
    }
    else
    {
      return min(a2[mina2], a1[mina1]);
    }
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
