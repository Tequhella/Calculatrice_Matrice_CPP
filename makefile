CC  	= g++

G++ 	= -g -Wall

Sources = Calculatrice_Matrice_CPP/sources

all: $(Sources)/main.o $(Sources)/matrice.o
	$(CC) $(G++) $(Sources)/main.o $(Sources)/matrice.o -o calculatrice_matrice_CPP_0-0-1

obj/main.o: 
	$(CC) $(G++) -c $(Sources)/main.cpp

obj/matrice.o: 
	$(CC) $(G++) -c $(Sources)/matrice.cpp

clean:
	rm -f obj/*.o calculatrice_matrice_CPP_0-0-1
