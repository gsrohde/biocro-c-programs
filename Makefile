main: main.o
	clang++ -o main main.o exampleLibrary.so

main.o: main.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c main.cpp
