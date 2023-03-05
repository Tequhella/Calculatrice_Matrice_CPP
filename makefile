CC  	= gcc

FLAGS 	= -g -Wall

obj	= C-Matrice/obj

all: $(obj)/main.o $(obj)/fonction.o
	$(CC) $(FLAGS) $(obj)/main.o $(obj)/fonction.o -o C-Matrice

$(obj)/main.o: 
	$(CC) $(FLAGS) -c main.c -o $(obj)/main.o

$(obj)/fonction.o: 
	$(CC) $(FLAGS) -c fonction.c -o $(obj)/fonction.o

clean:
	rm -f $(obj)/*.o C-Matrice
