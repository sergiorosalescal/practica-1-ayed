// AUTOR: Sergio Rosales Calzadilla
// FECHA: 8/02/2024
// EMAIL: alu0101635590@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// Según la guía de estilo de Google se pueden usar dos sintaxis, las cuales 
// son "//" o bien "/* */"

#include "rational_t.hpp"

// El constructor evita una posible indeterminacion en la división
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos
/*
Según la Guía de Estilo de Google no se deben dejar más de uno o dos espacios,
en blanco entre funciones/métodos.
*/

// pauta de estilo [83]: tipo retornado en línea anterior al método
/*
Según la Guía de Estilo de Google el tipo de retorno,
debe ubicarse en las misma línea que en nombre de la función.
*/

int
rational_t::get_num() const
{
  return num_;
}



int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  rational_t primera_fraccion {get_num(), get_den()};
  return (fabs(primera_fraccion.value() - (r.value())) < precision);
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  rational_t primera_fraccion {get_num(), get_den()};
  return ((r.value() - primera_fraccion.value()) > precision);
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  rational_t primera_fraccion {get_num(), get_den()};
  return ((primera_fraccion.value() - r.value()) > precision);
}


//operaciones
rational_t
rational_t::add(const rational_t& r)
{
  rational_t primera_fraccion {get_num(), get_den()};
  rational_t segunda_fraccion {r.get_num(), r.get_den()};
  int numerador_resultante {(primera_fraccion.get_num() * segunda_fraccion.get_den()) + (primera_fraccion.get_den() * segunda_fraccion.get_num())};
  int denominador_resultante {primera_fraccion.get_den() * segunda_fraccion.get_den()};
  rational_t fraccion_final {numerador_resultante, denominador_resultante};
  return fraccion_final;
}



rational_t
rational_t::substract(const rational_t& r)
{
  rational_t primera_fraccion {get_num(), get_den()};
  rational_t segunda_fraccion {r.get_num(), r.get_den()};
  int numerador_resultante {(primera_fraccion.get_num() * segunda_fraccion.get_den()) - (primera_fraccion.get_den() * segunda_fraccion.get_num())};
  int denominador_resultante {primera_fraccion.get_den() * segunda_fraccion.get_den()};
  rational_t fraccion_final {numerador_resultante, denominador_resultante};
  return fraccion_final;
}



rational_t
rational_t::multiply(const rational_t& r)
{
  rational_t primera_fraccion {get_num(), get_den()};
  rational_t segunda_fraccion {r.get_num(), r.get_den()};
  int numerador_resultante {primera_fraccion.get_num() * segunda_fraccion.get_num()};
  int denominador_resultante {primera_fraccion.get_den() * segunda_fraccion.get_den()};
  rational_t fraccion_final {numerador_resultante, denominador_resultante};
  return fraccion_final;
}



rational_t
rational_t::divide(const rational_t& r)
{
  rational_t primera_fraccion {get_num(), get_den()};
  rational_t segunda_fraccion {r.get_num(), r.get_den()};
  int numerador_resultante {primera_fraccion.get_num() * segunda_fraccion.get_den()};
  int denominador_resultante {primera_fraccion.get_den() * segunda_fraccion.get_num()};
  rational_t fraccion_final {numerador_resultante, denominador_resultante};
  return fraccion_final;
}



// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
