// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: header file containin the implementation of 
// the polynomial class

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

/* Polynomial Class Implementations */

// ============================================================
// Function: get_num_terms
// Description: An accessor function that returns the number of
// terms in the polynomial
// Precondition: num_terms must have been assigned a value
// in one of the polynomial class's constructors
// Postcondition: 
// Returns: an integer representing the number of terms in the polynomial
// ============================================================
template <class T>
int polynomial<T>::get_num_terms() const
{
  return num_terms;
}

// ============================================================
// Function: add_term
// Description: Adds a term to a polynomial's terms array
// Precondition: The term and polynomial classes must have the same
// template type.
// Postcondition: The term will be added into the polynomial object's terms
// array and num_terms will be incremented by 1
// Param t : the term to be added to the polynomial
// Returns: nothing
// ============================================================
template <class T>
void polynomial<T>::add_term(const term<T>& t)
{
  num_terms++;
  if(num_terms == 1)
  {
  	terms = new term<T>[num_terms];
	terms[0] = t;
  }
  else
  {
    polynomial<T> temp(num_terms);
	for(int j = 0; j < num_terms - 1; j++)
    {
      temp[j] = terms[j];
    }
  
    temp[num_terms - 1] = t;
    delete[] terms;
    terms = new term<T>[num_terms];
    for(int k = 0; k < num_terms; k++)
    {
      terms[k] = temp[k];
    }
  }
}

/*======= Constructors =======*/

// Default Constructor
template <class T>
polynomial<T>::polynomial()
{
  num_terms = 0;
}

// Constructor that creates a polynomial with one term
// Parameter: coefficient = the term's coefficient
// Parameter: exponent = the term's exponent
template <class T>
polynomial<T>::polynomial(const T coefficient, const T exponent)
{
  num_terms = 1;
  terms = new term<T>[num_terms];
  terms[0].coefficient = coefficient;
  terms[0].exponent = exponent;	
}

// Copy Constructor
template <class T>
polynomial<T>::polynomial(const polynomial<T> & source)
{
  num_terms = source.get_num_terms();
  terms = new term<T>[num_terms];
  for(int i = 0; i < num_terms; i++)
  {
  	terms[i] = source.terms[i];
  }
}

// Constructor that creates a polynomial of size num
// Parameter: num = amount of terms the new polynomial will have
template <class T>
polynomial<T>::polynomial(const int num)
{
  num_terms = num;
  terms = new term<T>[num_terms];
}

/* ======= Overloaded Operators ======= */
template <class T>
term<T>& polynomial<T>::operator [](const int i) const
{
  return terms[i];
}

template <class T>
polynomial<T> polynomial<T>::operator +(const polynomial<T> & p)
{
  polynomial<T> temp(*this);
  int size = temp.get_num_terms();
  int p_size = p.get_num_terms();
  for(int i = 0; i < p_size; i++)
  {
  	int j = 0;
  	bool exponent_match = false;
  	while( j < size && !exponent_match )
  	{
  	  if(p[i].exponent == temp[j].exponent)
  	  {
  	  	temp[j] += p[i];
  	  	exponent_match = true;
  	  }
  	  j++;
  	}
  	if( !exponent_match )
  	{
  	  //temp = temp.add_term(p[i]);
  	  temp.add_term(p[i]);
  	}
  } 
  return temp;
}

template <class T>
polynomial<T> polynomial<T>::operator -(const polynomial<T> & p)
{
  polynomial<T> temp(*this);
  int p_terms = p.get_num_terms();
  for(int i = 0; i < p_terms; i++)
  {
  	int j = 0;
  	bool exponent_match = false;
  	while( j < num_terms && !exponent_match )
  	{
  	  if(p[i].exponent == temp[j].exponent)
  	  {
  	  	temp[j] -= p[i];
  	  	exponent_match = true;
  	  }
  	  j++;
  	}
  	if( !exponent_match )
  	{
  	  //temp = temp.add_term(-p[i]);
  	  temp.add_term(-p[i]);
  	}
  } 	
  return temp;
}

template <class T>
polynomial<T> polynomial<T>::operator *(const float n)
{
  polynomial<T> temp(*this);
  for(int i = 0; i < num_terms; i++)
  {
  	temp[i] *= n;
  }
  return temp;
}

template <class T>
polynomial<T> polynomial<T>::operator -()
{
  polynomial<T> temp(*this);
  for(int i = 0; i < num_terms; i++)
  {
  	temp[i] *= -1;
  }
  return temp;
}

template <class T>
polynomial<T>& polynomial<T>::operator =(const polynomial<T> & p)
{
  if (num_terms != p.get_num_terms() )
  {
    num_terms = p.get_num_terms();
    delete[] terms;
    terms = new term<T>[num_terms];
  }
  for(int i = 0; i < num_terms; i++)
  {
  	terms[i] = p[i];
  }
  return (*this);
}

template <class T>
polynomial<T>& polynomial<T>::operator +=(const polynomial<T> & p)
{
  /*	
  polynomial<T> temp(*this);
  temp = temp + p;
  return temp;
  */
  *this = *this + p;
  return (*this);
}

template <class T>
polynomial<T>& polynomial<T>::operator -=(const polynomial<T> & p)
{
  *this = *this - p;
  return (*this);
}

template <class T>
T polynomial<T>::operator()(const int n) const
{
  T result = 0;
  for(int i = 0; i < num_terms; i++)
  {
  	result += terms[i].coefficient * pow(n, terms[i].exponent);
  }
  return result;
}

template <class T>
bool polynomial<T>::operator ==(const polynomial<T> & p) const
{
  bool equal = true;
  if(num_terms != p.get_num_terms())
  {
  	return false;
  }
  for(int i = 0; i < num_terms; i++)
  {
    if( terms[i].coefficient != p.terms[i].coefficient 
       || terms[i].exponent != p.terms[i].exponent )
    {
      equal = false;
	  i = num_terms; // break loop   	
    }
  }
  return equal;
}

template<class T>
bool polynomial<T>::operator !=(const polynomial<T> & p) const
{
  return !(*this == p);
}

template <class T>
polynomial<T> polynomial<T>::operator ~()
{
  polynomial<T> temp(*this);
  for(int i = 0; i < temp.num_terms; i++)
  {
  	if(temp[i].coefficient >= 0)
  	{
	  temp[i].coefficient = temp[i].coefficient * -1;
    }
  }
  return temp;
}

template <typename J>
ostream& operator <<(ostream& out, const polynomial<J> & p)
{
  for (int i = 0; i < p.get_num_terms(); i++)
  {
    if(i == 0)
    {
      out << p[i].coefficient;
    }
    else if(p[i].coefficient < 0)
    {
      out << " - ";
	  if(-p[i].coefficient != 1)
	  {
	    cout << -p[i].coefficient;
      }
	}
    else
    {
      out << " + ";
	  if(p[i].coefficient != 1)
	  {
	  cout << p[i].coefficient;
      }
    }
    if(p[i].exponent != 0)
    {
	  out << "x";
	  if(p[i].exponent != 1)
	  {
	    out << "^" << p[i].exponent;
      }
    }
  }
  return out;
}

template <typename J>
polynomial<J> operator *(const float n, const polynomial<J> & p)
{
  polynomial<J> temp(p);
  return temp * n;
}
#endif
