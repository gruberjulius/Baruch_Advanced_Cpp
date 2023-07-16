#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>
#include <iostream>

int main() {

	// Part A

	boost::numeric::ublas::mapped_matrix<std::complex<double>> cm(4, 4);
	cm(0, 0) = (2, 2); 
    cm(1, 1) = (2, 2); 
    cm(2, 2) = (2, 2);
    cm(3, 3) = (2, 2);

	std::cout << cm << std::endl;

	// Part B

    // Create an upper triangular matrix with row-major storage
    boost::numeric::ublas::matrix<double, boost::numeric::ublas::row_major> upperRow(3, 3, 0.0);
    for (size_t i = 0; i < upperRow.size1(); ++i)
    {
        for (size_t j = i; j < upperRow.size2(); ++j)
        {
            upperRow(i, j) = i + j;
        }
    }

    std::cout << "Upper Triangular Matrix (Row-Major):\n" << upperRow << std::endl;

    // Create a lower triangular matrix with column-major storage
    boost::numeric::ublas::matrix<double, boost::numeric::ublas::column_major> lowerCol(3, 3, 0.0);
    for (size_t i = 0; i < lowerCol.size1(); ++i)
    {
        for (size_t j = 0; j <= i; ++j)
        {
            lowerCol(i, j) = i + j;
        }
    }

    std::cout << "Lower Triangular Matrix (Column-Major):\n" << lowerCol << std::endl;




	// Part C
	
	boost::numeric::ublas::matrix<double> dense(3, 3, 1);
	boost::numeric::ublas::triangular_adaptor<boost::numeric::ublas::matrix<double>, boost::numeric::ublas::lower> newl(dense);
	std::cout << newl << std::endl;
}
