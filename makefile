suffixtrie: suffixmain.o suffixtrie.o
	gcc -o suffixtrie suffixmain.o suffixtrie.o
	
suffixmain.o: suffixmain.c suffixtrie.o
	gcc -c suffixmain.c
	
suffixtrie.o: suffixtrie.h suffixtrie.c
	gcc -c suffixtrie.c
