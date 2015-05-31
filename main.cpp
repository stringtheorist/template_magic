#include <iostream>
#include <random>

#include "matrix.hpp"


void fillRandomValues(Matrix &A)
{
  std::random_device rD;
  std::mt19937 gen(rD());
  std::uniform_real_distribution<> dist(-1.0, 1.0);

  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < A.getCols(); j++) {
      A.setValue(i, j, dist(gen));
    }
  }
}

#if 0

void printMatrix(Matrix &A)
{
  std::cout << "Matrix [" << A.getRows() << " x " << A.getCols() << "] :" << std::endl;
  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < A.getCols(); j++) {
      std::cout << A(i, j) << " ";
    }
    std::cout << std::endl;
  }
}
#endif


int main (int argc, char **argv)
{
//  Matrix A(5, 10);
 // Matrix B(10, 4);
  //Matrix C(5, 4);
  Matrix A(5, 5);
  Matrix B(5, 5);
  Matrix C(5, 5);

//  fillRandomValues(A);
 // fillRandomValues(B);
 A.setIdentity();
 B.setIdentity();

  C = 2.0*A*B + A;

  //printMatrix(C);
  C.printMatrix();
  return 0;
}
