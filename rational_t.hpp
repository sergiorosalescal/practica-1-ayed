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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
/*
 Definimos una cierta precision para comprobar,
 la igualdad de datos tipo "double"
*/
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
  /*
  Segun la Guia de Estilo de Google es recomendable empezar con "public", 
  luego "protected" y finalmente "private". 
  Omitiendo las secciones que se encuentren vacías.
  */ 

public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios

  /*
  Segun la Guia de Estilo de Google, la identacion de el "public", 
  "protected" y "private" debe de ser de 1 espacio, con respeto de la clase.
  Sin embargo, los metodos, sobrecargas... en su interior sí que deben de llevar,
  una identación de 2 espacios.
  */ 

  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;  // Retorna el cociente de la division del num/den

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;  // Se encarga de escribir por pantalla
  void read(istream& = cin);  // Lee valores introducidos por el usuario
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  // En una clase los atributos privados también deben de terminar en "_"
  int num_, den_;
};
