
#include <iostream>
using namespace std;

struct Actividad
{
  int inicio;
  int fin;
};

void greedy(Actividad arr[], Actividad sol[], int MAX)
{
  // sort() => ordeno por actividad.fin ascendente
  int finActual = arr[0].fin;
  int k = 0;
  for (int i = 0; i < MAX; i++)
  {
    if (finActual < arr[i + 1].inicio)
    {
      sol[k++] = arr[i];
      finActual = arr[i].fin;
    }
  }
}

int main()
{
  return 0;
}