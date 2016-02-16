// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: Header file containing the declaration of
// the polynomial class

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <cmath>
#include <vector>
#include <iostream>
#include "term.h"
using namespace std;

// ============================================================
// Class polynomial
// The polynomial class represents a polynomial.
// Example: 4x^3 + 5x^4 + 6x^5
// It contains a dynamically-allocated array of term objects, terms,
// and num_terms represents the current number of terms in the polynomial.
// ============================================================

template <class T>
class polynomial
{
  private:
    int num_terms;
    term<T>* terms;
  
  public:
  	/* Accessor Functions */
  	int get_num_terms() const;
  	 	
  	/* Mutator Functions */
  	void add_term(const term<T> & t);
  	
  	/* Constructors */
  	polynomial(); // default constructor
  	polynomial(const T coefficient, const T exponent); // creates a monomial 
  	polynomial(const polynomial<T> & source); // copy constructor
  	polynomial(const int num);
  	
  	/* Destructor */
  	~polynomial() { delete[] terms; };
  	
  	/* Overloaded Operators */
  	polynomial<T> operator +(const polynomial<T> & p);
  	polynomial<T> operator -(const polynomial<T> & p);
  	polynomial<T> operator -(); // unary -
  	polynomial<T> operator *(const float n);
  	polynomial<T> & operator +=(const polynomial<T> & p);
  	polynomial<T> & operator -=(const polynomial<T> & p);
  	bool operator ==(const polynomial<T> & p) const;
  	bool operator !=(const polynomial<T> & p) const;
  	polynomial<T> & operator =(const polynomial<T> & p);
  	polynomial<T> operator ~();
  	term<T>& operator [](const int i) const;
  	T operator()(const int n) const;
  	template <typename J>
	friend ostream& operator <<(ostream& out, const polynomial<J> & p);
	template <typename J>
	friend polynomial<J> operator *(const float n, const polynomial<T> & p);
};

#include "polynomial.hpp"
#endif
