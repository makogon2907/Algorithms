CFLAGS=-Wall -Werror -fsanitize=address 

%:
	g++ $@.cpp -std=c++17 -o $@ $(CFLAGS) && ./$@ <input.txt >output.txt && rm $@
