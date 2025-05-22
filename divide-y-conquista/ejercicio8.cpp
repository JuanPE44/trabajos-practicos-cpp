/*
8) Se dispone de un arreglo de enteros que representa las variaciones registradas por sensores de
pulso o ECG (electrocardiograma) a lo largo de un período de tiempo. Los valores positivos
indican aumentos en la señal, y los negativos, descensos. Se desea analizar la señal para identificar
el intervalo más significativo en cuanto a variación, es decir, el subarreglo contiguo cuya suma
sea máxima.
a) Implementar un algoritmo en C++ que identifique el subarreglo contiguo con la mayor suma
posible. Este intervalo representa el período donde se observa la mayor variación acumulada
en la señal medida.
b) Determinar la complejidad temporal y analizar qué ocurre si todos los valores del arreglo
fueran positivos. ¿Es necesario aplicar la misma técnica en ese caso o existe una solución más
simple?

maxArr(arr, inicio, fin) {
  si (inicio == fin)
    return arr[inicio]

  mitad = inicio + (fin-inicio) / 2

  max_izq = maxArr(arr, inicio, mitad)
  max_der = maxArr(arr, mitad+1, fin)
  max_mitad = calcMaxMitad(arr, mitad, inicio, fin)

   return max(max_izq, max_der, max_mitad)
}

calcMaxMitad(arr, mitad, inicio, fin) {
    suma ← 0
    max_izquierda ← -infinito
    Para i desde mitad - 1 hasta inicio (en reversa):
        suma ← suma + arr[i]
        Si suma > max_izquierda:
            max_izquierda ← suma

    suma ← 0
    max_derecha ← -infinito
    Para i desde mitad hasta fin
        suma ← suma + arr[i]
        Si suma > max_derecha:
            max_derecha ← suma

    Retornar max_izquierda + max_derecha
}
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int sumaMaxMid(int arr[], int mid, int inicio, int fin)
{
  // sum izq
  int suma = 0;
  int maxIzq = INT_MIN;
  for (int i = mid; i >= inicio; i--)
  {
    suma += arr[i];
    if (suma > maxIzq)
    {
      maxIzq = suma;
    }
  }
  // sum der
  suma = 0;
  int maxDer = INT_MIN;
  for (int i = mid + 1; i <= fin; i++)
  {
    suma += arr[i];
    if (suma > maxDer)
    {
      maxDer = suma;
    }
  }
  return maxIzq + maxDer;
}

int sumaMax(int arr[], int inicio, int fin)
{
  if (fin == inicio)
    return arr[inicio];

  int mid = inicio + (fin - inicio) / 2;

  int maxIzq = sumaMax(arr, inicio, mid);
  int maxDer = sumaMax(arr, mid + 1, fin);
  int maxMid = sumaMaxMid(arr, mid, inicio, fin);

  return max({maxIzq, maxDer, maxMid});
}

int main()
{
  int MAX = 10;
  int datos[] = {2, -1, 3, -4, 5, 6, -2, 4, -7, 2};
  int maxSuma = sumaMax(datos, 0, MAX - 1);
  return 0;
}
