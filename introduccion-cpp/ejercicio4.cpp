/*
Dada la ecuación de segundo grado: ax2 + bx + c, al calcular el discriminante discr = b2 - 4ac, se
pueden presentar tres casos distintos:
Si discr > 0.0, las dos raíces son reales y distintas, y valen:
x1= (-b + (discr)1/2 ) / (2a) y x2 = (-b - (discr)1/2 ) / (2a).
Si discr = 0.0, las dos raíces son reales e iguales, y valen:
x1 = x2 = -b / (2a)
Si discr < 0.0, las dos raíces son complejas conjugadas. Las partes real e imaginaria valen:
xr = -b / (2a) y xi = (-discr)1/2 / (2a)
Codificar un programa que permita obtener las raíces de una ecuación de segundo grado, sabiendo
que los valores a, b y c deben ser ingresados por el usuario.
*/

#include <iostream>
#include <cmath>
// esto me evita usar std::
using std::cin;
using std::cout;
using std::endl;
int main()
{
  int a, b, c;
  double x1, x2, xr, xi;
  cout << "Ingrese 3 numeros: ";
  cin >> a >> b >> c;
  double discr = b * b - 4 * a * c;
  cout << "Ecuacion: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
  if (discr > 0.0)
  {
    x1 = (-b + pow(discr, 1 / 2)) / (2 * a);
    x2 = (-b - pow(discr, 1 / 2)) / (2 * a);
    cout << "Raiz x1: " << x1 << endl;
    cout << "Raiz x2: " << x2 << endl;
  }
  else if (discr == 0.0)
  {
    x1 = x2 = -b / (2 * a);
    cout << "Raiz x1: " << x1 << endl;
    cout << "Raiz x2: " << x2 << endl;
  }
  else
  {
    xr = -b / (2 * a);
    xi = (-discr) * 1 / 2 * (2 * a);
    cout << "Raiz xr: " << xr << endl;
    cout << "Raiz xi: " << xi << endl;
  }
  return 0;
}