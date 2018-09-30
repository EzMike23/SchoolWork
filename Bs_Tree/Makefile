mymatrix: datatype.o bs_tree.o matrix.o main.o 
	gcc -o mymatrix datatype.o bs_tree.o matrix.o main.o 
	
main.o:  main.c
	gcc -c main.c

datatype.o:  datatype.c datatype.h
	gcc -c datatype.c
	
bs_tree.o:  bs_tree.c bs_tree.h
	gcc -c bs_tree.c
	
matrix.o:  matrix.c matrix.h
	gcc -c matrix.c
	
clean:
	-rm -f *.o
	-rm -f mymatrix
