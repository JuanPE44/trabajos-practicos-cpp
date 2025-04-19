/*
Escribir un programa que lea dos números ingresados por teclado (separados por un espacio ‘ ‘), los
multiplique e imprima el resultado por pantalla.

*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int a, b;
  cin >> a >> b;
  cout << a << " " << b << " " << (a * b) << endl;

  return 0;
}