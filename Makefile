binarymatrices.exe:
	g++ -I ./eigen-3.4.0/ main.cpp mymath.cpp -o binarymatrices.exe

test3:
	./binarymatrices.exe 3

clean:
	rm binarymatrices.exe