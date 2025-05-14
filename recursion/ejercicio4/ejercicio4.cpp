/*
Considerar un tablero de n × n de celdas blancas y negras, distribuidas de cualquier
manera. Una región blanca (negra) es un conjunto contiguo máximo de celdas
blancas (negra): dos celdas blancas (negra) son contiguas si son adyacentes de
forma horizontal o vertical.
El problema consiste en que dada una celda y un color, se pide pintar de ese color
toda la región a la que pertenece la celda. Por ejemplo, si para el tablero de la figura
anterior se especifica la celda (3, 2) y el color gris, el resultado debe ser el tablerdo
de la derecha.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int FILAS = 15;
const int COLUMNAS = 15;

void imprimirTablero(int tablero[FILAS][COLUMNAS])
{
  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      if (tablero[i][j] == 3)
      {
        cout << "\033[31m" << tablero[i][j] << " \033[0m";
      }
      else
      {
        cout << tablero[i][j] << " ";
      }
    }
    cout << endl;
  }
}

void cargarTablero(int tablero[FILAS][COLUMNAS])
{
  srand(time(0));
  for (int i = 0; i < FILAS; i++)
  {
    for (int j = 0; j < COLUMNAS; j++)
    {
      tablero[i][j] = rand() % 2;
    }
  }
}

void pintar(int (&tablero)[FILAS][COLUMNAS], int fila, int columna, int color)
{
  if (fila >= FILAS || fila < 0 || columna >= COLUMNAS || columna < 0 || tablero[fila][columna] != 0)
  {
    return;
  }
  tablero[fila][columna] = color;
  pintar(tablero, fila + 1, columna, color);
  pintar(tablero, fila - 1, columna, color);
  pintar(tablero, fila, columna + 1, color);
  pintar(tablero, fila, columna - 1, color);
}

int main()
{
  int tablero[FILAS][COLUMNAS];
  cargarTablero(tablero);
  imprimirTablero(tablero);
  pintar(tablero, 0, 0, 3);
  cout << " " << endl;
  imprimirTablero(tablero);
  return 0;
}
