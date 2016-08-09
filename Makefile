CFLAGS=-g -Wall
CC=arm-linux-gcc
AR=arm-linux-ar
RANLIB=arm-linux-ranlib
LIBS=-L./ -lcgic

all: libcgic.a pass.cgi

install: libcgic.a
	cp libcgic.a /usr/local/lib
	cp cgic.h /usr/local/include
	@echo libcgic.a is in /usr/local/lib. cgic.h is in /usr/local/include.

libcgic.a: cgic.o cgic.h
	rm -f libcgic.a
	$(AR) rc libcgic.a cgic.o
	$(RANLIB) libcgic.a

pass.cgi: pass.o libcgic.a
	$(CC) pass.o -o pass.cgi ${LIBS}

clean:
	rm -f *.o *.a pass.cgi

test:
	$(CC) -D UNIT_TEST=1 cgic.c -o cgicunittest
	./cgicunittest
