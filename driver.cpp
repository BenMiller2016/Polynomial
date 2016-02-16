// Programmer: Ben Miller
// Date: 2/12/16
// Course: CS 5201 : Object-Oriented Numerical Modeling
// Description: main file which tests the implementation
// of the polynomial class and infinity norm

#include "polynomial.h"
#include "infinity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
  ifstream myfile;
  int num_polynomials, number_of_terms, vectsize, num_spaces, num_char;
  string line, sub;
  bool exponent_match = false;
  vector<polynomial<float> > polyvect;
  //remember to do exception handling and use argv for commandline file name
  myfile.open("polynomial.txt");
  
  /* ===== Error Handling ===== */
  
  /* Make sure file opens properly */
  if( !(myfile.is_open()) )
  {
    cout << "Error: Could not open file \n";
    return 0;
  }
  myfile >> num_polynomials;
  
  /* Check File Format For Errors */
  for(int i = 0; i < num_polynomials+1; i++)
  {
	if( getline(myfile, line) )
    {
      num_spaces = 0;
      num_char = 0;
      for(int j = 0; j < line.size(); j++)
      {
        if(line[j] == ' ')
        {
          num_spaces++;
          if(j+1 == line.size())
          {
          	cout << "Error: ended line with a space\n";
          	return 0;
          }
        }
        else if(num_spaces == 0)
        {
          num_char++;
        }
      }
      sub = line.substr(0,num_char);
      if ( num_spaces !=  atoi(sub.c_str())* 2)
      {
        cout << "Error: Incorrect number of terms in line " << i << endl;
        return 0;
      }
    }
    else
    { // reached end of file too early
      cout << "Error: Not enough polynomials in the file.\n";
      return 0;
    }
  }
  // should be at end of file, so getline should fail
  if( getline(myfile, line) )
  {
  	cout << "Error: Too many polynomials in this file.\n";
  	return 0;
  }
  
  myfile.clear();
  myfile.seekg(0, ios::beg);
  myfile >> num_polynomials;
  
  /* ===== Extract Polynomials From File ===== */
  for(int i = 0; i < num_polynomials; i++)
  {
	myfile >> number_of_terms;
	term<float> t;
	polynomial<float> p;
    for(int j = 0; j < number_of_terms; j++)
    {
	  myfile >> t.coefficient >> t.exponent;
      for(int k = 0; k < p.get_num_terms(); k++)
      {
        if(t.exponent == p[k].exponent)
        {
          p[k].coefficient += t.coefficient;
          exponent_match = true;
        }
      }
      if(!exponent_match)
      {
	    p.add_term(t);
      }
      exponent_match = false;
    }
    polyvect.push_back(p);
  }
  myfile.close();
  
  /* ===== Test outputs =====*/  
  cout << polyvect[0] << endl;
  cout << polyvect[1] << endl;
  polyvect[0] += polyvect[1];
  cout << polyvect[0] << endl;
  cout << -polyvect[0] << endl;
  cout << polyvect[0](-1) << endl;
  cout << 4 * polyvect[2] << endl;
  cout << (~polyvect[3])(2) << endl;
  
  infinity<float> norm;
  float max_magnitude = norm(polyvect);
  cout << max_magnitude;
  
  return 0;
}
