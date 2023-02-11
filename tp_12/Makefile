
FLAGS= -Wall -Wextra -fsanitize=address,undefined

clean : 
	rm *.o build/*


string_function.o : string_function.c
	gcc $(FLAGS) -c -o $@ $<

naive_search.o : naive_search.c
	gcc $(FLAGS) -c -o $@ $<

int_list.o : int_list.c
	gcc $(FLAGS) -c -o $@ $<

rabin_karp.o : rabin_karp.c
	gcc $(FLAGS) -c -o $@ $<

boyer_moore.o : boyer_moore.c
	gcc $(FLAGS) -c -o $@ $<

test.o : test.c
	gcc $(FLAGS) -c -o $@ $<


test : test.o string_function.o naive_search.o int_list.o rabin_karp.o boyer_moore.o
	gcc $(FLAGS) -o build/$@ $^