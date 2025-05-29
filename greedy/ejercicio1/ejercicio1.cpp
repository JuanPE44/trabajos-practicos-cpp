/*
1. Problema de la Mochila. Se tienen n objetos y una mochila. Para i = 1,2,..n, el objeto i
tiene un peso positivo pi y un valor positivo vi. La mochila puede llevar un peso que no
sobrepase P. El objetivo es llenar la mochila de tal manera que se maximice el valor de
los objetos transportados, respetando la limitación de capacidad impuesta. Los objetos
pueden ser fraccionados, si una fracción xi (0  xi  1) del objeto i es ubicada en la
mochila contribuye en xipi al peso total de la mochila y en xivi al valor de la carga.
*/

#include <iostream>
#include <algorithm>
using namespace std;


struct Objeto {
  double valor;
  double peso;
};
const int MAX = 3;

void mostrarObjetos(Objeto objetos[], int MAX) {
  for(int i=0;i<MAX;i++) {
    cout << "objeto " << i << " valor: " << objetos[i].valor << " peso: " << objetos[i].peso << endl;
  }
}


void greedy(Objeto objetos[]) {
  sort(objetos,objetos + MAX, [](const Objeto& a, const Objeto& b) {
    return a.valor > b.valor;
  });
  mostrarObjetos(objetos,MAX);
}

int main() {
  Objeto objetos[] = {{24,15},{15,10},{25,18}};
  cout << "Arreglo: " << endl;
  mostrarObjetos(objetos,MAX);
  cout << "Arreglo: " << endl;
  greedy(objetos);
  return 0;
}
