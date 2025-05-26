

#include <iostream>

using namespace std;

int cantRepetido(int arreglo[], int num, int i, int MAX)
{
  int count = 0;
  while (i < MAX && arreglo[i] == num)
  {
    count++;
    i++;
  }
  return count;
}

int maxRepetido(int arreglo[], int MAX)
{
  int i = 0;
  int cantMax = 0;
  int maxNum = 0;
  while (i < MAX)
  {
    int cantRep = cantRepetido(arreglo, arreglo[i], i, MAX);

    if (cantRep > cantMax)
    {
      cantMax = cantRep;
      maxNum = arreglo[i];
    }
    i += cantRep;
  }
  return maxNum;
}

int main()
{
  int arregloOrdenado[] = {1, 2, 3, 4, 4, 4, 5, 5, 6, 7, 8, 8, 8, 8};
  int cant = maxRepetido(arregloOrdenado, 14);
  return 0;
}