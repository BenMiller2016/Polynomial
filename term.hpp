// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: header file containin the implementation of 
// the polynomial class

#ifndef TERM_HPP
#define TERM_HPP

/* Term Struct Implementation */
/*======= Overloaded Operator =======*/
template <class T>
term<T>& term<T>::operator +=(const term<T>& t)
{
  if(exponent == t.exponent)
  {
  	coefficient = coefficient + t.coefficient;
  }
  return (*this);
}

template <class T>
term<T>& term<T>::operator -=(const term<T>& t)
{
  if(exponent == t.exponent)
  {
  	coefficient = coefficient - t.coefficient;
  }
  return (*this);
}

template <class T>
term<T>& term<T>::operator *=(const T n)
{
  coefficient = coefficient * n;
  return (*this); 
}

template <class T>
term<T> term<T>::operator -() const
{
  term<T> temp;
  temp.coefficient = coefficient * -1;
  temp.exponent = exponent;
  return temp; 
}

template <class T>
term<T>& term<T>::operator =(const term<T> & t)
{
  coefficient = t.coefficient;
  exponent = t.exponent;
  return (*this);
}

#endif
