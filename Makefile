TRGDIR=./
OBJ=./obj
CPPFLAGS= -Wall -pedantic -std=c++17 -iquote -Iinc

_start_: URL_S

${OBJ}:
	mkdir ${OBJ}

URL_S: ${OBJ}/main.o ${OBJ}/Wektor.o ${OBJ}/LZespolona.o
	g++ -Wall -pedantic -o URL_S ${OBJ}/main.o ${OBJ}/Wektor.o ${OBJ}/LZespolona.o

${OBJ}/main.o: src/main.cpp inc/Wektor.h inc/UkladRownan.h inc/MacierzKw.h
	g++ -c ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/Wektor.o: src/Wektor.cpp inc/Wektor.h inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o ${OBJ}/Wektor.o src/Wektor.cpp

${OBJ}/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.h inc/Wektor.h
	g++ -c ${CPPFLAGS} -o ${OBJ}/MacierzKw.o src/MacierzKw.cpp

${OBJ}/UkladRownan.o: src/UkladRownan.cpp inc/UkladRownan.h inc/MacierzKw.h inc/Wektor.h
	g++ -c ${CPPFLAGS} -o ${OBJ}/UkladRownan.o src/UkladRownan.cpp

clear:
	rm -f ${TRGDIR}/URL_S ${OBJ}/*
