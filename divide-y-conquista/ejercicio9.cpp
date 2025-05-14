#include <iostream>
#include <algorithm> // para std::max
using namespace std;

template <typename T>
class Arbin
{
private:
  struct Nodo
  {
    T dato;
    Nodo *izq;
    Nodo *der;

    Nodo(const T &e, Nodo *i = nullptr, Nodo *d = nullptr)
        : dato(e), izq(i), der(d) {}
  };

  Nodo *raiz;

  // Métodos auxiliares
  static void destruir(Nodo *n)
  {
    if (n != nullptr)
    {
      destruir(n->izq);
      destruir(n->der);
      delete n;
    }
  }

  static Nodo *copiar(Nodo *n)
  {
    if (n == nullptr)
      return nullptr;
    return new Nodo(n->dato, copiar(n->izq), copiar(n->der));
  }

  static bool existeElemento(Nodo *n, const T &e)
  {
    if (n == nullptr)
      return false;
    if (n->dato == e)
      return true;
    return existeElemento(n->izq, e) || existeElemento(n->der, e);
  }

  static int altura(Nodo *n)
  {
    if (n == nullptr)
      return 0;
    return 1 + max(altura(n->izq), altura(n->der));
  }

  static int cantidadNodos(Nodo *n)
  {
    if (n == nullptr)
      return 0;
    return 1 + cantidadNodos(n->izq) + cantidadNodos(n->der);
  }

  static bool iguales(Nodo *a, Nodo *b)
  {
    if (a == nullptr && b == nullptr)
      return true;
    if (a == nullptr || b == nullptr)
      return false;
    return a->dato == b->dato &&
           iguales(a->izq, b->izq) &&
           iguales(a->der, b->der);
  }

  static bool esHoja(Nodo *n)
  {
    if (n == nullptr)
      return true;
    return (n->izq == nullptr && n->der == nullptr);
  }

public:
  // Constructor vacío (inicArbin)
  Arbin() : raiz(nullptr) {}

  // Constructor no vacío (crearArbin)
  Arbin(const Arbin &izq, const Arbin &der, const T &dato)
  {
    raiz = new Nodo(dato, copiar(izq.raiz), copiar(der.raiz));
  }

  // Constructor de copia
  Arbin(const Arbin &otro)
  {
    raiz = copiar(otro.raiz);
  }

  // Destructor
  ~Arbin()
  {
    destruir(raiz);
  }

  // Operaciones
  bool vacioArbin() const
  {
    return raiz == nullptr;
  }

  T raizArbin() const
  {
    if (vacioArbin())
      throw logic_error("Árbol vacío");
    return raiz->dato;
  }

  Arbin subIzquierdo() const
  {
    if (vacioArbin())
      throw logic_error("Árbol vacío");
    Arbin sub;
    sub.raiz = copiar(raiz->izq);
    return sub;
  }

  Arbin subDerecho() const
  {
    if (vacioArbin())
      throw logic_error("Árbol vacío");
    Arbin sub;
    sub.raiz = copiar(raiz->der);
    return sub;
  }

  bool existeElemento(const T &e) const
  {
    return existeElemento(raiz, e);
  }

  int altura() const
  {
    return altura(raiz);
  }

  int cantidadNodos() const
  {
    return cantidadNodos(raiz);
  }

  bool esHoja() const
  {
    return esHoja(raiz);
  }

  bool operator==(const Arbin &otro) const
  {
    return iguales(raiz, otro.raiz);
  }
};