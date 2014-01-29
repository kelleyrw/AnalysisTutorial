# simple Makefile for test4

# target
all: bin/test4

# rule to make the exe
bin/test4: src/test4.cpp lib/libmodule.so
	g++ -Iinclude src/test4.cpp -Llib -lmodule -o bin/test4

lib/libmodule.so: obj/module1.o obj/module2.o
	g++ -shared obj/module1.o obj/module2.o -o lib/libmodule.so

obj/module1.o: src/module1.cpp
	g++ -c src/module1.cpp -Iinclude -o obj/module1.o

obj/module2.o: src/module2.cpp
	g++ -c src/module2.cpp -Iinclude -o obj/module2.o

# clean up
clean:
	if [ -f lib/libmodule.so ]; then rm lib/libmodule.so; fi
	if [ -f bin/test4 ]; then rm bin/test4; fi
	if [ -f obj/module1.o ]; then rm obj/module1.o; fi
	if [ -f obj/module2.o ]; then rm obj/module2.o; fi
	if [ -f obj/test4.o ]; then rm obj/test4.o; fi

# PHONY means these rules are always out of date
.PHONY: all clean
