CFLAGS=-Wall -Werror -fsanitize=address -std=c++17

%:
	g++ $@.cpp -o $@ $(CFLAGS) && ./$@ <input.txt >output.txt && rm $@
