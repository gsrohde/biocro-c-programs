LIBRARY_FILE_EXTENSION = so
BIOCRO_LIB = $(shell Rscript -e "cat(system.file('libs', 'BioCro.$(LIBRARY_FILE_EXTENSION)', package = 'BioCro'))")
EXAMPLE_LIB = $(shell Rscript -e "cat(system.file('libs', 'exampleLibrary.$(LIBRARY_FILE_EXTENSION)', package = 'exampleLibrary'))")

all: main main2

main: main.o test_module_creator_impl.o test_module_factory.o utils.o $(BIOCRO_LIB) $(EXAMPLE_LIB)
	clang++ -o main main.o test_module_creator_impl.o test_module_factory.o utils.o $(BIOCRO_LIB) $(EXAMPLE_LIB)

# Change the link order for the module libraries:
main2: main.o test_module_creator_impl.o test_module_factory.o utils.o $(BIOCRO_LIB) $(EXAMPLE_LIB)
	clang++ -o main2 main.o test_module_creator_impl.o test_module_factory.o utils.o $(EXAMPLE_LIB) $(BIOCRO_LIB)

main.o: main.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c main.cpp

test_module_creator_impl.o: test_module_creator_impl.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c test_module_creator_impl.cpp

test_module_factory.o: test_module_factory.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c test_module_factory.cpp

utils.o: utils.cpp
	clang++ -mmacosx-version-min=10.13 -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I/usr/local/include   -fPIC  -Wall -g -O2  -c utils.cpp


