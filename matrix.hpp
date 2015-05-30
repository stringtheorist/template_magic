#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cassert>

class Matrix
{
  private:
    double *values;
    int rows;
    int cols;

  public:
    Matrix(int m, int n)
    {
      rows = m;
      cols = n;
      values = new double[m*n];
    }

    ~Matrix() 
    {
      delete[] values;
    }

    int getRows() const
    {
      return rows;
    }

    int getCols() const
    {
      return cols;
    }

    void setValue(int i, int j, double val)
    {
      values[i*cols + j] = val;
    }

    double operator () (int i, int j) const
    {
      assert(i < rows);
      assert(j < cols);
      return values[i*cols + j];
    }
    template<typename a>
    Matrix& operator=(const a& expr)
    {

      assert(rows == expr.getRows());
      assert(cols == expr.getCols());
      for (int i = 0; i < expr.getRows(); i++)
      {
	for (int j = 0; j < expr.getCols(); j++) 
	{
	  values[i*cols + j] = expr(i, j);
	}
      }

      return *this;
    }
};

template <typename a, typename b>
class Sum
{
  public:
    explicit Sum (const a& A, const b& B)
      : A_(A) , B_(B)
    {}
    double operator () (int i, int j) const 
    {
      return A_(i, j) + B_(i, j);
    }
    int getRows() const
    {
      return A_.getRows();
    }
    int getCols() const
    {
      return A_.getCols();
    }

  private:
    const a& A_;
    const b& B_;

};

template <typename a, typename b>
Sum<a, b> operator+ (const a& A, const b& B) 
{
  return Sum<a, b> (A, B);
}

template <typename a, typename b>
class Product
{
  public:
    explicit Product (const a& A, const b& B)
      : A_(A) , B_(B)
    {}
    double operator () (int i, int j) const 
    {
      assert(i < A_.getRows());
      assert(j < B_.getCols());
      double val = 0.0;
      assert(A_.getCols() == B_.getRows());
      for (int k = 0; k < A_.getCols(); k++)
      {
	val += A_(i, k) * B_(k, j);
      }
      return val;
    }
    int getRows() const
    {
      return A_.getRows();
    }
    int getCols() const
    {
      return B_.getCols();
    }

  private:
    const a& A_;
    const b& B_;
};


template <typename a, typename b>
Product<a, b> operator* (const a& A, const b& B) 
{
  return Product<a, b> (A, B);
}


#endif
