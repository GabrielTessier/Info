
FLAGS= -Wall -Wextra -fsanitize=address,undefined
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=build/obj/%.o)

clean : 
	rm -rf build

build/obj/%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

build/build:$(OBJ)
	gcc $(FLAGS) -o $@ $^

install:
	mkdir -p build/obj
	make build/build
