GCC    	  = g++
CFLAGS 	  = -g -Wall
TARGET 	  = calculatriceMatrice_CPP
OBJS      = obj/main.o obj/matrice.o

all: $(OBJS)
	$(GCC) $(CFLAGS) -o $(TARGET) $(OBJS)

obj/main.o: sources/main.cpp headers/matrice.h
#check if obj directory exists, if not create it
	@if [ ! -d "obj" ]; then mkdir obj; fi
	$(GCC) $(CFLAGS) -c sources/main.cpp -o obj/main.o

obj/matrice.o: sources/matrice.cpp headers/matrice.h headers/fractionizer.h
	$(GCC) $(CFLAGS) -c sources/matrice.cpp -o obj/matrice.o

clean:
	rm -f $(OBJS) $(TARGET)