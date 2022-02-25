all:
	tcc -lssl rnum.c -o rnum

install:
	install rnum /usr/local/bin/

uninstall:
	rm /usr/local/bin/rnum

clean:
	rm rnum
