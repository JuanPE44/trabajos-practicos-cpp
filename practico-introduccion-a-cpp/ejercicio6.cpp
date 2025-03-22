/**
Argumentos al programa: Escribir un programa que lea un mensaje desde el teclado, reemplace un
carácter por otro e imprima el mensaje resultante por pantalla. El reemplazo de caracteres se realizará
de acuerdo a los parámetros que recibirá la función main desde la línea de comandos (Por ejemplo:
<proyecto.exe> A B, para reemplazar cada ocurrencia de A por B).

 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Faltan argumentos" << endl;
    return 1;
  }
  string mensaje;
  cout << "Ingrese un mensaje: ";
  cin >> mensaje;
  for (int i = 0; i < mensaje.length(); i++)
  {
    if (argv[1][0] == mensaje[i])
    {
      mensaje[i] = argv[2][0];
    }
  }
  cout << mensaje << endl;
  return 0;
}