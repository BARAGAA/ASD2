# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = -lm	-lstdc++ 			
LIBSDIR = 

# fichiers du projet
SRC = main.cpp ticket.cpp vconsigne.cpp colis.cpp 
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
ticket.o: ticket.hpp
colis.o: bagage.hpp
colis.o: colis.hpp
vconsigne.o: vconsigne.hpp
vconsigne.o: ticket.hpp
vconsigne.o: case.hpp
vconsigne.o: bagage.hpp
vconsigne.o: colis.hpp
main.o: ticket.hpp 
main.o: vconsigne.hpp
main.o:	bagage.hpp
main.o: case.hpp
main.o: colis.hpp
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o