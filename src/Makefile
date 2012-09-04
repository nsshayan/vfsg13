mainHeader.o:mainHeader.c ../include/mainHeader.h
	gcc -c mainHeader.c ../include/mainHeader.h -o mainHeader.o

linkedList.o:linkedList.c ../include/linkedList.h
	gcc -c linkedList.c ../include/linkedList.h -o linkedList.o

nArrayTree.o:nArrayTree.c ../include/nArrayTree.h
	gcc -c nArrayTree.c ../include/nArrayTree.h -o nArrayTree.o

bst.o:bst.c ../include/bst.h
	gcc -c bst.c ../include/bst.h -o bst.o

hashTable.o:hashTable.c ../include/hashTable.h
	gcc -c hashTable.c ../include/hashTable.h -o hashTable.o

testProgram.o:testProgram.c
	gcc -c testProgram.c -o testProgram.o

finalout:mainHeader.o bst.o nArrayTree.o linkedList.o testProgram.o
	gcc -c mainHeader.o bst.o nArrayTree.o linkedList.o testProgram.o -o finalout
