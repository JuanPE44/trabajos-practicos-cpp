

#include <iostream>;

void greedyCamioncito(int gasolinera[], int numeroG, int gasoil, int &sol[], int fin)
{
  // sort() => ordenar por kilometros de gasolinera ascendente

  int recorrido = 0;
  int k = 0;
  for (int i = 0; i < numeroG; i++)
  {

    if ((recorrido + gasoil) < gasolinera[i])
    {

      if (sol[k] = gasolinera[i - 1] || (recorrido + gasoil) >= fin)
      {
        return;
      }

      sol[k++] == gasolinera[i - 1];
    }
  }
}

int main()
{
  return 0;
}