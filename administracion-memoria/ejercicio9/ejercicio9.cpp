/*
Realizar el seguimiento para los dos puntos anteriores usando el conjunto {-1, 1,
4, 9}. Calcular el número de operaciones para buscar los elementos {0,-1, 4,
10} y comparar con la complejidad teórica. Medir el tiempo de ejecución promedio
de cada programa y comparar.
*/

/*
Implementar una función iterativa para hacer una búsqueda binaria para un arreglo
de enteros ordenado.
*/

#include <iostream>

using namespace std;

void mostrarArreglo(int *arreglo, int MAX)
{
  cout << "Arreglo: ";
  for (int i = 0; i < MAX; i++)
  {
    cout << arreglo[i] << " ";
  }
  cout << endl;
}

// Búsqueda lineal que cuenta comparaciones
int buscarEnArreglo(int *arreglo, int numero, int MAX, int &comparaciones)
{
  for (int i = 0; i < MAX; i++)
  {
    comparaciones++;
    if (arreglo[i] == numero)
      return i;
  }
  return -1;
}

int busquedaBinaria(int *arreglo, int numero, int MAX, int &comparaciones)
{
  int inicio = 0;
  int fin = MAX - 1;
  int medio;

  while (inicio <= fin)
  {
    medio = inicio + (fin - inicio) / 2;
    comparaciones++;

    if (arreglo[medio] == numero)
    {
      return medio;
    }
    else if (arreglo[medio] > numero)
    {
      fin = medio - 1;
    }
    else
    {
      inicio = medio + 1;
    }
  }
  return -1;
}

int main()
{
  int arreglo[] = {-1, 1, 4, 9};
  int MAX = sizeof(arreglo) / sizeof(arreglo[0]);

  int numerosBuscar[] = {0, -1, 4, 10};
  int cantidadBuscar = sizeof(numerosBuscar) / sizeof(numerosBuscar[0]);

  mostrarArreglo(arreglo, MAX);

  cout << "Busqueda Lineal";
  for (int i = 0; i < cantidadBuscar; i++)
  {
    int comparaciones = 0;
    int encontrado = buscarEnArreglo(arreglo, numerosBuscar[i], MAX, comparaciones);
    cout << "Buscando " << numerosBuscar[i] << ": ";
    if (encontrado != -1)
      cout << "Encontrado en posicion " << encontrado;
    else
      cout << "No encontrado";
    cout << " | Comparaciones: " << comparaciones << endl;
  }

  cout << "Busqueda Binaria";
  for (int i = 0; i < cantidadBuscar; i++)
  {
    int comparaciones = 0;
    int encontrado = busquedaBinaria(arreglo, numerosBuscar[i], MAX, comparaciones);
    cout << "Buscando " << numerosBuscar[i] << ": ";
    if (encontrado != -1)
      cout << "Encontrado en posicion " << encontrado;
    else
      cout << "No encontrado";
    cout << " | Comparaciones: " << comparaciones << endl;
  }

  return 0;
}
