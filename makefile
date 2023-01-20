PREFIX=${HOME}/.local

rnum: rnum.c
	cc -lcrypto rnum.c -o rnum

install: rnum rnum.1
	mkdir -p ${PREFIX}/bin
	install rnum ${PREFIX}/bin/
	mkdir -p ${PREFIX}/share/man/man1
	install rnum.1 ${PREFIX}/share/man/man1/

uninstall:
	rm ${PREFIX}/bin/rnum ${PREFIX}/share/man/man1/rnum.1

clean:
	rm rnum
