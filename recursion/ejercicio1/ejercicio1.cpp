/*
Dado un entero en binario representado mediante un arreglo de 0’s y 1’s, escriba un
algoritmo recursivo que devuelva el resultado de la conversión a decimal.

00001111 = 7
*/

#include <iostream>
#include <cmath>

using namespace std;

int convertirDecimal(int *arregloBinario, int n, int i = 0)
{
  if (i > n)
  {
    return 0;
  }
  return convertirDecimal(arregloBinario, n, i + 1) + pow(2, i) * arregloBinario[n - i];
}

int main()
{
  const int MAX_ARREGLO = 5;
  int arregloBinario[MAX_ARREGLO] = {1, 0, 0, 0, 0};
  int decimal = convertirDecimal(arregloBinario, MAX_ARREGLO - 1);
  return 0;
}