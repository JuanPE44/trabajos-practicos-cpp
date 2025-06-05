

#include <iostream>
#include <algorithm>
using namespace std;

int maxMid(int arr[], int inicio, int fin)
{
  int maximo = 1;
  int count = 1;
  for (int i = inicio; i < fin; i++)
  {
    if (arr[i] < arr[i + 1])
    {
      count++;
    }
    else
    {
      maximo = max(maximo, count);
      count = 1;
    }
  }
  maximo = max(maximo, count);
  return maximo;
}

int func(int arr[], int inicio, int fin)
{
  if (inicio >= fin)
    return 1;

  int mid = (fin + inicio) / 2;
  int izq = func(arr, inicio, mid);
  int der = func(arr, mid + 1, fin);
  int maxmid = maxMid(arr, inicio, fin);

  return max(max(izq, der), maxmid);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int resultado = func(arr, 0, n - 1);
  cout << "El resultado de func es: " << resultado << endl;
  return 0;
}