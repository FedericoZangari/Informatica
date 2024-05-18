CC = g++

all: compila esegui

compila: esame.cc funzioni.cc
	$(CC) -o $@ $< funzioni.cc `root-config --cflags` `root-config --libs`

esegui:
	./compila
