PREFIX=/usr/local

all: rnum.c
	cc -lcrypto rnum.c -o rnum

install:
	install rnum ${PREFIX}/bin/

uninstall:
	rm ${PREFIX}/bin/rnum

clean:
	rm rnum
