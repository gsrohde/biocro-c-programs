all: main main2

main: main.o BioCro.so exampleLibrary.so
	clang++ -o main main.o BioCro.so exampleLibrary.so 

main2: main.o BioCro.so exampleLibrary.so
	clang++ -o main2 main.o exampleLibrary.so BioCro.so

main.o: main.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c main.cpp
