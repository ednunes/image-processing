BINFOLDER := bin/
INCFOLDER := include/
OBJFOLDER := obj/
SRCFOLDER := source/


CC := g++
CFLAGS := -Wall -ansi

SRCFILES := $(wildcard source/*.cpp)

all: $(SRCFILES:source/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o finalBinary

obj/%.o: source/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./include

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
run:
	./finalBinary




