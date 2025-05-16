#ifndef LISTA_R_H
#define LISTA_R_H

template <typename T>
struct Nodo
{
  T dato;
  Nodo<T> *siguiente;
};

template <typename T>
class Lista_R
{
private:
  Nodo<T> *cabeza;
  unsigned int longitud;

public:
  // Constructor: iniciarLista
  Lista_R();

  // Agregar al inicio
  void agregarInicio(const T &valor);

  // Agregar al final
  void agregarFinal(const T &valor);

  // Eliminar último (pre: lista no vacía)
  void eliminarUltimo();

  // Obtener nodo i-ésimo (pre: lista no vacía y rango válido)
  T obtenerNodo(unsigned int i) const;

  // isVacia
  bool isVacia() const;

  // size
  unsigned int size() const;

  // isRango (pre: lista no vacía)
  bool isRango(unsigned int i) const;
};

#endif
