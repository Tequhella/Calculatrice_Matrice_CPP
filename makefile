CC  	= g++

G++ 	= -g -Wall

Sources = Calculatrice_Matrice_CPP/sources

obj		= Calculatrice_Matrice_CPP/obj

all: $(obj)/main.o $(obj)/matrice.o
	$(CC) $(G++) $(obj)/main.o $(obj)/matrice.o -o calculatrice_matrice_CPP_0-0-12

$(obj)/main.o: 
	$(CC) $(G++) -c $(Sources)/main.cpp -o $(obj)/main.o

$(obj)/matrice.o: 
	$(CC) $(G++) -c $(Sources)/matrice.cpp -o $(obj)/matrice.o

clean:
	rm -f $(obj)/*.o calculatrice_matrice_CPP_0-0-12
