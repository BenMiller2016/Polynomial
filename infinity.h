// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: Header file containing the declaration of
// the infinity class

#ifndef INFINITY_H
#define INFINITY_H

// ============================================================
// Class infinity
// The infinity class represents the infinity norm operation,
// which finds the highest magnitude of the polynomials
// The magnitude of a polynomial is the square root of the
// sum of the squares of each term's coefficient 
// ============================================================
template <class T>
class infinity
{
  public:
  float operator()(const vector<polynomial<T> >& polynomials);
};

#include "infinity.hpp"
#endif
