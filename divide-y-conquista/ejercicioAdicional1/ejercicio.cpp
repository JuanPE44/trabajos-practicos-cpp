

 
#include <iostream>
using namespace std;

int contarRecurrencias(int arr[], int inicio, int fin, int num) {
  int contador = 0;
  for(int i = inicio;i<=fin;i++){
    if(arr[i]==num) 
      contador++;
  }
  return contador;
}

int existeElMayoritario(int arr[], int inicio, int fin, int MAX) {

  if(inicio == fin) {
    return arr[inicio];
  }

  if(inicio+1 == fin) {
    if(arr[inicio] == arr[fin]) {
      return arr[inicio];
    }
    return -1;
  }

  int mid = (fin+inicio)/2;
  int candidatoIzq = existeElMayoritario(arr, inicio, mid, MAX);
  int candidatoDer = existeElMayoritario(arr, mid+1, fin, MAX);
  

  int cantDer = contarRecurrencias(arr,inicio,fin,candidatoDer);
  int cantIzq = contarRecurrencias(arr,inicio,fin,candidatoIzq);
    int len = fin - inicio + 1
  
  if(cantIzq > len/2) {
    return candidatoIzq;
  }

  if(cantDer > len/2) {
    return candidatoDer;
  }

  return -1;
}

int main() {
  return 0;
}
