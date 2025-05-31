// ejercicio parcial divide y conquista, obtener indice

#include <iostream>
using namespace std;

int obtenerIndiceCambio(int arr1[], int arr2[], int inicio, int fin)
{
  if (inicio == fin)
  {
    return inicio;
  }

  if (inicio + 1 == fin)
  {
    if (arr1[inicio] == arr2[inicio])
    {
      return fin;
    }
    else
    {
      return inicio;
    }
  }

  int mid = (inicio + fin) / 2;

  if (arr1[mid] != arr2[mid])
  {
    return obtenerIndiceCambio(arr1, arr2, inicio, mid);
  }
  else
  {
    return obtenerIndiceCambio(arr1, arr2, mid + 1, fin);
  }
}

int main()
{
  int arr1[] = {1, 2, 3, 7};
  int arr2[] = {1, 2, 8, 9};
  int n = sizeof(arr1) / sizeof(arr1[0]);

  int indice = obtenerIndiceCambio(arr1, arr2, 0, n - 1);

  cout << "El indice donde cambian los arreglos es: " << indice << endl;
  cout << "arr1[" << indice << "] = " << arr1[indice] << ", arr2[" << indice << "] = " << arr2[indice] << endl;

  return 0;
}