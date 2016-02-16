// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: Header file containing the declaration of
// the term class

#ifndef TERM_H
#define TERM_H

// ============================================================
// Class term
// The term class represents a term of a polynomial.
// Example: 4x^2
// It contains a coefficient and an exponent.
// It has overloaded operators to handle addition, subtraction,
// multiplication, assignment, and negation.
// ============================================================
template <class T>
struct term
{
  T coefficient;
  T exponent;
  term<T> & operator +=(const term<T> & t);	
  term<T> & operator -=(const term<T> & t);
  term<T> & operator *=(const T n);
  term<T> & operator =(const term<T> & t);
  term<T> operator -() const;
};

#include "term.hpp"
#endif
