CC = gcc
LIBS = -lpthread
RESULT = tinyweb

tinyweb: tiny_web.c tiny_web.h csapp.o doit.o serve_static.o serve_dynamic.o read_requesthdrs.o parse_uri.o
	$(CC) tiny_web.c csapp.o doit.o  serve_static.o serve_dynamic.o read_requesthdrs.o parse_uri.o $(LIBS) -o $(RESULT)

tinywebself: tiny_web.c tiny_web.h csapp.o doit.o serve_static.o serve_dynamic.o read_requesthdrs.o parse_uri.o
	$(CC) tiny_web.c csapp.o doit.o  serve_static.o serve_dynamic.o read_requesthdrs.o parse_uri.o $(LIBS) -o $(RESULT)
	rm -f *.o

doit.o: doit.c
	$(CC) doit.c -c -o doit.o

parse_uri.o: parse_uri.c
	$(CC) parse_uri.c -c -o parse_uri.o

caspp.o: csapp.c csapp.h
	$(CC) csapp.c -c -o csapp.o

read_requesthdrs.o: read_requesthdrs.c
	$(CC) read_requesthdrs.c -c -o read_requesthdrs.o

serve_dynamic.o: serve_dynamic.c
	$(CC) serve_dynamic.c -c -o serve_dynamic.o

serve_static.o: serve_static.c
	$(CC) serve_static.c -c -o serve_static.o

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(RESULT)