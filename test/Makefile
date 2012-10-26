OBJECTS = mainHeader.o test.o narrtest.o

newfile:$(OBJECTS)
	gcc $(OBJECTS) -o newfile

mainHeader.o:../src/mainHeader.c ../include/mainHeader.h
	gcc -c ../src/mainHeader.c -o ../bin/mainHeader.o -I ../include/

test.o:../include/mainHeader.h test.c
	gcc -c test.c -o ../bin/test.o -I ../include/

narrtest.o:../include/mainHeader.h narrtest.c
	gcc -c narrtest.c -o ../bin/narrtest.o -I ../include/ 
