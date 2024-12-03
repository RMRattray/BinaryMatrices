#include <iostream>
#include <Eigen/Dense>
#include "mymath.h"

using Eigen::MatrixXd;
 
int main(int argc, char * * argv)
{
    // Step 1 - find the argument n and the corresponding Fibonacci number
    if (argc != 2) {
        std::cout << "Usage: ./binarymatrices.exe n" << std::endl;
        return EXIT_FAILURE;
    }
    int n = std::atoi(argv[1]);
    int f = fib(n);
    // std::cout << "n: " << n << "\tf: " << f << std::endl;

    // Step 2:  Get all possible rows
    Eigen::ArrayXi r(f);
    r(0) = 0;
    r(1) = 1;
    int i = 0;
    int j = 2;
    int m = 2;
    int tm = 1;
    int tmp = 2;
    while (m <= n) {
        i = 0;
        while (r(i) < tm) {
            r(j) = tmp + r(i);
            ++i;
            ++j;
        }
        ++m;
        tm = tmp;
        tmp <<= 1;
    }
    // std::cout << r << std::endl;

    // Step 3:  Compatibility matrix
    Eigen::MatrixXi c(f,f);
    for (i = 0; i < f; ++i) {
        j = 0;
        while (j < i) {
            c(i, j) = c(j, i);
            ++j;
        }
        while (j < f) {
            c(i, j) = r(i) & r(j) ? 0 : 1;
            ++j;
        }
    }
    // std::cout << c << std::endl << std::endl;

    // Raise the matrix to a power
    Eigen::MatrixXi cn = c;
    while (n) {
        --n;
        cn *= c;
        // std::cout << cn << std::endl << std::endl;
    }

    // Final output
    std::cout << cn(0,0) << std::endl;
}