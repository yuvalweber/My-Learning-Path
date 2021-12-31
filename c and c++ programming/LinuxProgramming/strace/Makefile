my_strace: strace.o helperFunctions.o decoder.o 
	gcc -g -Wall -Werror -o my_strace strace.o helperFunctions.o decoder.o 

decoder.o: ./decoder/decoder.c
	gcc -c ./decoder/decoder.c -o decoder.o

helperFunctions.o: helperFunctions.c 
	gcc -c helperFunctions.c -o helperFunctions.o

strace.o:
	gcc -c strace.c -o strace.o

clean:
	$(RM) my_strace decoder.o helperFunctions.o strace.o
