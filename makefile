UNAME := $(shell uname)

CC=g++
ifeq ($(UNAME), Linux)
	LDFLAGS=-lglfw -lSOIL -lGLEW -lGL -lm -I ./
endif
ifeq ($(UNAME), Darwin)
	LDFLAGS=-framework OpenGL -framework GLUT -Wall -Wno-deprecated
endif

all: ; $(CC) src/abfa.c lib/* -o abfa $(LDFLAGS)

.c: ; $(CC) $@.c -o $@ $(LDFLAGS)

clean: ; rm -f abfa
