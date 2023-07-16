#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

int main()
{
    // Create vectors
    ublas::vector<double> v1(3);
    v1(0) = 1.0;
    v1(1) = 2.0;
    v1(2) = 3.0;

    ublas::vector<double> v2(3);
    v2(0) = 4.0;
    v2(1) = 5.0;
    v2(2) = 6.0;

    // Inner product
    double innerProduct = ublas::inner_prod(v1, v2);
    std::cout << "Inner product: " << innerProduct << std::endl;

    // Outer product
    ublas::matrix<double> outerProduct = ublas::outer_prod(v1, v2);
    std::cout << "Outer product:\n" << outerProduct << std::endl;

    // Adding two vectors
    ublas::vector<double> sum = v1 + v2;
    std::cout << "Sum of vectors: " << sum << std::endl;

    // Subtracting two vectors
    ublas::vector<double> diff = v1 - v2;
    std::cout << "Difference of vectors: " << diff << std::endl;

    // Euclidean norm of a vector
    double euclideanNorm = ublas::norm_2(v1);
    std::cout << "Euclidean norm of v1: " << euclideanNorm << std::endl;

    // L1 norm of a vector
    double l1Norm = ublas::norm_1(v2);
    std::cout << "L1 norm of v2: " << l1Norm << std::endl;

    // Max norm of a vector
    double maxNorm = ublas::norm_inf(v1);
    std::cout << "Max norm of v1: " << maxNorm << std::endl;

    // Matrix
    ublas::matrix<double> matrix(2, 3);
    matrix(0, 0) = 1.0;
    matrix(0, 1) = 2.0;
    matrix(0, 2) = 3.0;
    matrix(1, 0) = 4.0;
    matrix(1, 1) = 5.0;
    matrix(1, 2) = 6.0;

    // L1 norm of a matrix
    double matrixL1Norm = ublas::norm_1(matrix);
    std::cout << "L1 norm of matrix: " << matrixL1Norm << std::endl;

    // Max norm of a matrix
    double matrixMaxNorm = ublas::norm_inf(matrix);
    std::cout << "Max norm of matrix: " << matrixMaxNorm << std::endl;

    // Product of a matrix and a vector
    ublas::vector<double> result = ublas::prod(matrix, v1);
    std::cout << "Product of matrix and vector: " << result << std::endl;

    return 0;
}

