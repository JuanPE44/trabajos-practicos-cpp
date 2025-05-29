/*
Supongamos que se tiene un arreglo que contiene datos recolectados por dispositivos wearables,
como pulseras inteligentes o relojes deportivos. Este arreglo almacena mediciones de actividad
física registradas durante un cierto período de tiempo. Los datos pueden corresponder a un único
usuario o a múltiples usuarios. Se desea determinar el valor mínimo y el valor máximo de
actividad física registrados en el conjunto de datos, con el objetivo de detectar posibles patrones
de comportamiento. Por ejemplo, identificar posibles extremos en el comportamiento, como días
con niveles inusualmente bajos o altos de actividad, lo cual puede ser útil para generar
recomendaciones o alertas.
a) Resolver el problema implementando un algoritmo iterativo en lenguaje C++.
b) Resolver el problema utilizando la técnica de divide y conquista, también en C++.
c) Calcular la complejidad temporal de cada uno de los algoritmos implementados en los puntos
a) y b).
d) Realizar un análisis comparativo de eficiencia.
*/

#include <iostream>
using namespace std;

struct MinMax
{
  int min;
  int max;
};

// solucion iterativo

MinMax encontrarMinMax(int arr[], int n)
{
  MinMax res = {arr[0], arr[0]};
  for (int i = 1; i < n; ++i)
  {
    if (arr[i] < res.min)
      res.min = arr[i];
    if (arr[i] > res.max)
      res.max = arr[i];
  }
  return res;
}
// O(n)

// Solucion divide y conquista

MinMax encontrarMinMax(int arr[], int inicio, int fin)
{
  MinMax res;

  if (inicio == fin)
  {
    res.min = arr[inicio];
    res.max = arr[inicio];
    return res;
  }

  if (fin == inicio + 1)
  {
    res.min = min(arr[inicio],arr[fin]);
    res.max = max(arr[inicio], arr[fin]);
    return res;
  }
  
  // dividir
  int mid = (inicio + fin) / 2;

  // conquistar
  MinMax izquierda = encontrarMinMax(arr, inicio, mid);
  MinMax derecha = encontrarMinMax(arr, mid + 1, fin);
  
  //
  res.min = min(izquierda.min, derecha.min);
  res.max = max(izquierda.max, derecha.max);

  return res;
}

// O(log n)

int main()
{
  int arr[] = {1, 3, 8, 12, 9, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  MinMax minMax = encontrarMinMax(arr, n); // deberías obtener índice 3
  cout << "numero minimo: " << minMax.min << endl;
  cout << "numero maximo: " << minMax.max << endl;
  return 0;
}
