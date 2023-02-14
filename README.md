## Makefile explanation

### A bit about compilation and linking proccess:
*.c - source file\
*.o - compiled file. 

`cc -o main main.c fuction.c` this command builds and then links files to give us output final file\
`cc -c main.c` `cc -c function.c` does just compiling, creates main.o fuction.o\
`сс -o main main.o fuction.o` links two compiled files together\
This appoach can save resources for us, because compiling is resousrfull process, unlike linking. So we can compile only what was change, and then relink it with other files.\

### Let's create a simple makefile
`main: main.o fuction.o` -> what is needed fpr a main to be built (main's dependencies)\
`  cc -o main main.o fuction.o` -> which command should be used to build this\
`main.o: main.c`\
`  cc -c $(gg_sw) main.c`\
`function.o: fuction.c functions.h`\
`  cc -c $(gg_sw) fuction.c`\
`clean: `\
` rm main main.o fuction.o` -> cleaning unnesesary files, so project can be recompile from scratch\
`install: main`\
`  cp main /temp/Mainprogram` -> it will place main program to the folder spicified in teh path\
`gg_sw = -g` -> variable to compile with debugg optins\

