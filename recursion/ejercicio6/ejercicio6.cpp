
/*
Implementar la función que retorna el número de formas posibles en que podemos
formar un vuelto v a partir de una serie de billetes presentes en un arreglo billetes de
4 elementos. Por ejemplo para v = 1000 y un billete de 1000 debería retornar 1,
mientras que para v = 1000 y los billetes = {1, 10, 50,100} debería retornar 4246.
*/

#include <iostream>
using namespace std;

int cantidadCombinaciones(int billetes[], int v, int MAX)
{
  cout << v << endl;
  if (v == 0)
  {
    return 1;
  }
  if (v < 0)
  {
    return 0;
  }
  int total = 0;
  for (int i = 0; i < MAX; i++)
  {
    total += cantidadCombinaciones(billetes, v - billetes[i], MAX);
  }
  return total;
}

int main()
{
  const int MAX = 4;
  int billetes[] = {1, 10, 50, 100};
  int v = 1000;

  int cantidad = cantidadCombinaciones(billetes, v, MAX);
  return 0;
}