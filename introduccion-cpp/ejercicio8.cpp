/*
Escribir un programa que permita cargar un arreglo de números enteros a partir de información
provista por el usuario, y luego visualice estos valores pero en el orden inverso al ingresado.
Entrada al programa: dos líneas de texto que indican la cantidad de valores a ingresar y los valores en
sí, separados por un espacio. Por ejemplo:
5
10 2 3 1 7
Salida del programa: los valores, separados por un espacio, en el orden inverso al ingresado.
7 1 3 2 10
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void mostrarArreglo(int arreglo[], int tamaño)
{
  for (int i = 0; i < tamaño; i++)
  {
    cout << arreglo[i] << " ";
  }
  cout << "" << endl;
}

void mostrarArregloInvertido(int arreglo[], int tamaño)
{
  for (int i = tamaño - 1; i >= 0; i--)
  {
    cout << arreglo[i] << " ";
  }
  cout << "" << endl;
}

int main()
{
  int N;
  cout << "Ingrese el tamanio del arreglo: ";
  cin >> N;
  int arreglo[N];
  for (int i = 0; i < N; i++)
  {
    int num;
    cout << "ingrese un numero: ";
    cin >> num;
    arreglo[i] = num;
  }
  mostrarArreglo(arreglo, N);
  mostrarArregloInvertido(arreglo, N);
  return 0;
}