build:main.o BinSearchTree.o
	g++ -o build main.o BinSearchTree.o
main.o:main.cpp BinSearchTree.h
	g++ -c main.cpp
BinSearchTree.o:BinSearchTree.cpp BinSearchTree.h
	g++ -c BinSearchTree.cpp
clean:
	rm -f *.o