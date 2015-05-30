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


int main (int argc, char **argv)
{
  Matrix A(5, 10);
  Matrix B(10, 4);
  Matrix C(5, 4);

  fillRandomValues(A);
  fillRandomValues(B);

  C = A*B + C;

  printMatrix(C);
  return 0;
}
