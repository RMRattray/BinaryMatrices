This program takes in one command-line argument, an integer n, and calculates the nth term in [this series](https://oeis.org/A006506).
It depends on the library Eigen for matrix multiplication;
this can be downloaded [here](https://eigen.tuxfamily.org/index.php?title=Main_Page).
The Makefile expects to find the library in a subfolder of the repository called "eigen-3.4.0", which is the natural
result of unzipping the download.
