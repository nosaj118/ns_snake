CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O2
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC=main.c
OBJ=$(SRC:.c=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $<
