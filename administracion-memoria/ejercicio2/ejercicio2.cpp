#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rellenarRandom(int *arreglo, int tamaño)
{
  srand(time(nullptr)); // Semilla aleatoria
  for (int i = 0; i < tamaño; i++)
  {
    arreglo[i] = (rand() % 100 + 1); // Rango: [1, 100]
  }
}

void mostrarArreglo(int *ptr_arreglo, int tamaño)
{
  for (int i = 0; i < tamaño; i++)
  {
    cout << ptr_arreglo[i] << endl;
  }
}

int main()
{
  int n;
  cin >> n;

  int *numeros = new int[n];

  rellenarRandom(numeros, n);
  mostrarArreglo(numeros, n);
  delete[] numeros;
  return 0;
}