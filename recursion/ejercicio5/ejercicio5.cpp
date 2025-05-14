/*
Dado un arreglo de números y n un número natural. ¿Se puede formar n a partir de
sumar elementos del arreglo? Por ejemplo, para {5, 3, 9} y n = 31 se puede formar
31 = 2×9 + 2×5 + 1×3
*/

#include <iostream>
using namespace std;

bool puedeFormar(int arr[], int n, int MAX)
{
  cout << n << endl;
  if (n == 0)
  {
    return true;
  }
  if (n < 0)
  {
    return false;
  }
  for (int i = 0; i < MAX; i++)
  {
    if (puedeFormar(arr, n - arr[i], MAX))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  const int MAX = 3;
  int arr[] = {5, 3, 9};
  int n = 31;

  bool puede = puedeFormar(arr, n, MAX);
  return 0;
}