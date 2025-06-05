/*
Minimizar tiempo de espera. Un procesador debe atender n procesos. Se conoce de
antemano el tiempo que necesita cada uno de ellos. Determinar en qué orden el
procesador debe atender dichos procesos para minimizar la suma del tiempo que los
procesos están en el sistema.
Por ejemplo, para n = 3 se tienen, los procesos (p1, p2, p3) y tiempos de proceso (5, 10, 3)
*/

#include <iostream>
using namespace std;

void greedy(int arr[], int sol[], int MAX)
{
  // sort() => ordenar por tiempos de proceso ascendente

  for (int i = 0; i < MAX; i++)
  {
    sol[i] = arr[i];
  }
}

int main()
{
  return 0;
}
