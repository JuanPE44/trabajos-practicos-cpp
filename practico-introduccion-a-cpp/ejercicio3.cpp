/*
Escribir un programa que lea dos cadenas de caracteres ingresadas por teclado (separadas por un
espacio ‘ ‘), las concatene e imprima el resultado por pantalla.

*/

#include <iostream>
// esto me evita usar std::
using std::cin;
using std::cout;
using std::string;

int main()
{
  string a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}