hello.gb: hello.c
	lcc -o hello.gb hello.c

clean:
	rm -v *.gb
