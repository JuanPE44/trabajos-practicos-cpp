/*
Suponga un arreglo los nombres y números de teléfono de 5 personas. Buscar el
nombre correspondiente a un número de teléfono y el teléfono correspondiente a
una persona.
Para la entrada Juan,15678410; Ana,15974417; Pedro,15570327;
Maria,15609411; Carlos,15470424 realizar el seguimiento para buscar por
nombre: Ana y buscar por telefono: 15470424
*/

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
using namespace std;

const int MAX_CONTACTOS = 12;

struct Contacto
{
  string nombre;
  int telefono;
};

string buscarPorNumero(int numero, const Contacto *ptr)
{
  string nombre = "";
  int i = 0;
  bool encontro = false;
  while (!encontro && i < MAX_CONTACTOS)
  {
    if (!ptr->nombre.empty() && ptr->telefono == numero)
    {
      nombre = ptr->nombre;
      encontro = true;
    }
    cout << ptr << endl;

    i++;
    ptr++;
  }
  return nombre;
}

int buscarPorNombre(string nombre, const Contacto *ptr, unsigned int &iteraciones)
{
  int telefono = -1;
  int i = 0;
  bool encontro = false;
  iteraciones = 0;
  while (!encontro && i < MAX_CONTACTOS)
  {
    if (ptr->nombre == nombre)
    {
      telefono = ptr->telefono;
      encontro = true;
    }
    i++;
    ptr++;
    iteraciones++;
  }
  return telefono;
}

void costoTemporalBuscarPorNombre(const Contacto *contactos)
{
  cout << "N \t O \t\t T\n";
  for (unsigned int i = 0; i < MAX_CONTACTOS; i++)
  {
    unsigned int iteraciones;
    auto start = chrono::steady_clock::now();
    int numeros = buscarPorNombre(contactos[i].nombre, contactos, iteraciones);
    auto end = chrono::steady_clock::now();
    auto tiempo_ns = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << i << " \t " << iteraciones << " \t\t " << tiempo_ns << endl;
  }
}

void mostrarContactos(Contacto *ptr)
{
  cout << "\nLista de Contactos:\n";
  for (int i = 0; i < MAX_CONTACTOS; i++)
  {
    if (!ptr->nombre.empty())
    {
      cout << ptr->nombre << " - " << ptr->telefono << endl;
    }
    ptr++;
  }
}

int main()
{
  Contacto contactos[MAX_CONTACTOS] = {
      {"Juan", 15678410},
      {"Ana", 15974417},
      {"Pedro", 15570327},
      {"Maria", 15609411},
  };
  // string nombre = buscarPorNumero(15609411, contactos);
  // int numero = buscarPorNombre("Maria", contactos);
  // mostrarContactos(contactos);
  costoTemporalBuscarPorNombre(contactos);

  cout << "" << endl;
  return 0;
}
