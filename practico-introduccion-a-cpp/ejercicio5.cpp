/*
Un banco establece una tasa de interés para un fondo de inversión del 35% anual con pagos
mensuales; es decir, que cada mes se deposita en la cuenta del inversor el porcentaje de ganancia de
ese mes y se considera el total acumulado para el porcentaje del mes siguiente. Escriba un programa
que dado un monto y un plazo de vigencia del fondo calcule la nuevoSaldo esperada. Por ejemplo: si
se depositan $10.000 a 60 días la nuevoSaldo será de $591 aproximadamente al vencimiento del
plazo

35% anual
porcentaje de ganancia mes
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  const int MESES = 12;
  const int DIAS_AÑO = 365;
  const int DIAS_MES = DIAS_AÑO / MESES;

  double monto, nuevoSaldo, rentabilidad;
  int plazo;

  double tasaAnual = 0.35;
  double tasaMensual = tasaAnual / MESES;
  cout << "ingrese un monto:";
  cin >> monto;
  cout << "ingrese el plazo (en dias):";
  cin >> plazo;
  // plazo => dias
  nuevoSaldo = monto;
  int plazoMeses = plazo / DIAS_MES;
  for (int i = 1; i <= plazoMeses; i++)
  {
    nuevoSaldo = nuevoSaldo + (nuevoSaldo * tasaMensual);
  }
  rentabilidad = nuevoSaldo - monto;
  cout << "La nuevoSaldo esperada con un monto de " << monto << " y un plazo de " << plazo << " (dias): " << rentabilidad << endl;
  return 0;
}