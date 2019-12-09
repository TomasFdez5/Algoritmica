#ifndef STRASSEN_H
#define STRASSEN_H

#include <iostream>
#include <vector>

using namespace std;

void strassen(vector< vector<double> > &A, 
              vector< vector<double> > &B, 
              vector< vector<double> > &C, unsigned int tam);
#endif