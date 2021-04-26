CXX=g++
CXXFLAGS=-g -Wall -std=c++17
SOURCES=src/main.cc src/IP.cc src/IP_Header.cc src/Utils.cc src/TunIf.cc src/NetDev.cc src/ICMP.cc
OBJECTS=$(SOURCES:.cc=.o)

main.out:	$(OBJECTS)
	${CXX} ${CXXFLAGS} $^ -o $@

%.o:	%.cc
	${CXX} ${CXXFLAGS} -c $^ -o $@

buildtest:
	make -C ./test all

cleantest:
	make -C ./test clean

runtest:
	./test/test

clean:
	rm -f *.o *.out src/*.o
