CFLAGS=-Wall -Werror -fsanitize=address 

%:
	g++ $@.cpp -o $@ $(CFLAGS) && ./$@ <input.txt >output.txt && rm $@
