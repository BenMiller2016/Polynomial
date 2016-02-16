// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: header file containing the implementation of
// the infinity class

#ifndef INFINITY_HPP
#define INFINITY_HPP
#include <cmath> // square root ( sqrt() )
#include <vector>
// ============================================================
// Function operator()
// The operator() acts as a function to find the polynomial
// with the highest magnitude.  The magnitude of a polynomial is
// defined as square root of the sum of the squares of each term's 
// coefficient
// Parameter polynomials = a set of polynomials
// Returns: a float representing the highest magnitude
// ============================================================
template <class T>
float infinity<T>::operator ()(const vector<polynomial<T> >& polynomials)
{
  float max_magnitude = 0;
  float magnitude;
  float sum_of_squares;
  for(int i = 0; i < polynomials.size(); i++)
  {
    magnitude = 0;
    sum_of_squares = 0;
    for(int j = 0; j < polynomials[i].get_num_terms(); j++)
    {
      sum_of_squares += polynomials[i][j].coefficient * polynomials[i][j].coefficient;
    }
    magnitude = sqrt(sum_of_squares);
    if(magnitude > max_magnitude)
    {
      max_magnitude = magnitude;
    }
  }
  return max_magnitude;
}

#endif
