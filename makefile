# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = -lm	-lstdc++ 			
LIBSDIR = 

# fichiers du projet
SRC = main.cpp Ticket.cpp Consigne.cpp
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
ticket.o: ticket.hpp
storage.o: Consigne.hpp
storage.o: ticket.hpp
main.o: ticket.hpp 
main.o: consigne.hpp
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