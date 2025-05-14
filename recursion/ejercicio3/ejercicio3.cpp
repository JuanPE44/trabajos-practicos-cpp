/*
Genere un programa recursivo que indique si un string posee paréntesis
balanceados.
*/

#include <iostream>

using namespace std;

bool estaBalanceado(string texto, int indice = 0, int balance = 0)
{
  if (balance < 0)
    return false;

  if (indice >= texto.size())
    return balance == 0;

  if (texto[indice] == '(')
  {
    return estaBalanceado(texto, indice + 1, balance + 1);
  }
  else if (texto[indice] == ')')
  {
    return estaBalanceado(texto, indice + 1, balance - 1);
  }
  return estaBalanceado(texto, indice + 1, balance);
}

int main()
{
  string cadena1 = "((()))";
  string cadena2 = "((())))";
  bool c1 = estaBalanceado(cadena1);
  bool c2 = estaBalanceado(cadena2);
  return 0;
}