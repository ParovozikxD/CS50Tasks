#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

all: find generate

find: find.c helpers.c helpers.h cs50.c
	clang -o find find.c helpers.c cs50.c

generate: generate.c
	clang -o generate generate.c cs50.c

clean:
	rm -f *.o a.out core find generate