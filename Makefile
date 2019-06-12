all: aplicacio
aplicacio: aplicacio.c
	gcc -o aplicacio aplicacio.c
install:	aplicacio
	install -m 0755 aplicacio /usr/bin
