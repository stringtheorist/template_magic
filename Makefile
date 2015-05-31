all: mat_mull

mat_mull: main.cpp
	clang++ -o mat_mull -std=c++11 -stdlib=libc++ -Weverything main.cpp

clean:
	rm mat_mull
