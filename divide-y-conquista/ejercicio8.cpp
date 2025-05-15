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
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Resultado
{
  int max_suma;
  int inicio;
  int fin;
};

Resultado maxCruza(const vector<int> &arr, int izq, int mid, int der)
{
  int suma_izq = INT_MIN, suma_temp = 0;
  int max_izq = mid;
  for (int i = mid; i >= izq; i--)
  {
    suma_temp += arr[i];
    if (suma_temp > suma_izq)
    {
      suma_izq = suma_temp;
      max_izq = i;
    }
  }

  int suma_der = INT_MIN;
  suma_temp = 0;
  int max_der = mid + 1;
  for (int j = mid + 1; j <= der; j++)
  {
    suma_temp += arr[j];
    if (suma_temp > suma_der)
    {
      suma_der = suma_temp;
      max_der = j;
    }
  }

  return {suma_izq + suma_der, max_izq, max_der};
}

Resultado maxSubarrayDC(const vector<int> &arr, int izq, int der)
{
  if (izq == der)
  {
    return {arr[izq], izq, der};
  }

  int mid = (izq + der) / 2;

  Resultado res_izq = maxSubarrayDC(arr, izq, mid);
  Resultado res_der = maxSubarrayDC(arr, mid + 1, der);
  Resultado res_cruza = maxCruza(arr, izq, mid, der);

  if (res_izq.max_suma >= res_der.max_suma && res_izq.max_suma >= res_cruza.max_suma)
  {
    return res_izq;
  }
  else if (res_der.max_suma >= res_izq.max_suma && res_der.max_suma >= res_cruza.max_suma)
  {
    return res_der;
  }
  else
  {
    return res_cruza;
  }
}

int main()
{
  vector<int> datos = {2, -1, 3, -4, 5, 6, -2, 4, -7, 2};
  Resultado resultado = maxSubarrayDC(datos, 0, datos.size() - 1);

  cout << "Suma máxima: " << resultado.max_suma << endl;
  cout << "Intervalo: [" << resultado.inicio << ", " << resultado.fin << "]" << endl;

  return 0;
}
