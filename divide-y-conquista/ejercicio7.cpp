/*
Tu plataforma de e-commerce administra un arreglo ordenado S que contiene n cupones,
representados por valores monetarios enteros y distintos. Dado un valor entero x (que representa
un precio objetivo de compra), se desea determinar si existe al menos un par de cupones en el
arreglo cuya suma sea exactamente igual a x
a) Implementar un algoritmo en C++ que permita determinar si existe dicho par de cupones.
b) Calcule la complejidad temporal.
*/

#include <iostream>
using namespace std;

bool contieneCupones(int arr[], int inicio, int fin, int x)
{
  if(inicio == fin) {
    return false;
  }

  if(inicio+1 == fin) {
    if(arr[inicio] + arr[fin] == x) {
      return true;
    }
    return false;
  }

  int mid = (fin+inicio)/2;

  bool sumaIzq = contieneCupones(arr,inicio,mid,x);
  bool sumaDer = contieneCupones(arr,mid+1,fin,x);
 
  int i = inicio;
  int j = fin;

  while(i<j) {
   int suma = arr[i] + arr[j];
    if (suma == x) return true;
    else if (suma < x) i++;
    else j--;
  }
  return false;
}



int main()
{
  int arr[] = {1, 5, 8, 10, 14, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 60;
  bool encontrado = contieneCupones(arr, 0, n - 1, x);
  if (encontrado)
  {
    cout << "Si existe un par de cupones con suma " << x << endl;
  }
  else
  {
    cout << "No existe un par de cupones con suma " << x << endl;
  }
  return 0;
}
