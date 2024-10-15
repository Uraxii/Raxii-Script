exec = raxii-script.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install-linux:
	make
	cp ./raxii-script.out /usr/local/bin/raxii-script

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
