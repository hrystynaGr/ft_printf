## Makefile explanation

### A little about the compilation and linking process:
*.c - source file
*.o - compiled file.

`cc -o main main.c fuction.c` this command compiles and links files to get the final output file\
`cc -c main.c` `cc -c function.c` compiles only, creates main.o fuction.o\
`сс -o main main.o fuction.o` links two compiled files together\
With this approach we can save resources, because compiling is a resource-intensive process, unlike linking. So we can compile only what has been changed and then relink it to other files.

### Let us create a simple Makefile
`main: main.o fuction.o` -> what is needed for main to build (dependencies of main)\
` cc -o main main.o fuction.o` -> what command should be used to build this\
`main.o: main.c`\
` cc -c $(gg_sw) main.c`\
`function.o: fuction.c ft_printf.h`\
` cc -c $(gg_sw) fuction.c`\
` clean: `\
` rm main main.o fuction.o` - > cleans up unneeded files, so that the project can be recompiled from scratch\
`install: main`\
` cp main /temp/Mainprogram` -> puts the main program in the folder given in the path\
`gg_sw = -g` -> variable to compile with debug options

### rc crs
ar -rcs is used to compile a library.\
`r` means that if the library already exists, replace the old files within the library with your new files.\
`c` means create the library if it did not exist.\
`s` can be seen to mean sort (create a sorted index of) the library, so that it will be indexed and faster to access the functions in the library.\
Therefore, rcs can be seen to mean replace, create, sort.
