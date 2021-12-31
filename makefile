OUTPUT = DiGraph
CC = gcc
CFLAGS = -Wall -g
OBJ = graph.o nodes.o edges.o


all: output functions

main.o: main.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) main.c

graph.o: graph.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) graph.c

nodes.o: nodes.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) nodes.c

edges.o: edges.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) edges.c

functions: libfunctions.so

libfunctions.so: $(OBJ)
	$(CC) -shared -fPIC -o libfunctions.so $(OBJ)

output: main.o libfunctions.so
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o ./libfunctions.so

.PHONY: all clean functions output

clean:
	rm -f *.o *.so $(OUTPUT)
