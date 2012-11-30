OBJECTS1 = ../bin/vfsdriver.o ../bin/test.o ../bin/narrtest.o ../bin/makeDir.o  ../bin/listDir.o ../bin/bstTree.o ../bin/structhash1.o 
OBJECTS2 = ../bin/searchNary.o ../bin/searchFunc.o ../bin/stringtok.o ../bin/deleteDir.o ../bin/moveDir.o ../bin/addFile.o ../bin/listFile.o
OBJECTS3 = ../bin/updateFile.o ../bin/removeFile.o ../bin/exportFile.o ../bin/moveFile.o ../bin/copyFile.o ../bin/unmountVfs.o 
OBJECTS4 = ../bin/errorCheck.o ../bin/errorCheck1.o ../bin/currPtrRet.o ../bin/makeDirP.o ../bin/curPtrFunc1.o ../bin/manvfs.o

LDFFLAG = -g -Wall -I ../include/ -I ../src/

vfsdriver:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../include/funcPrototype3.h ../src/vfsdriver.c
	gcc $(LDFFLAG) -c ../src/vfsdriver.c  -o ../bin/vfsdriver.o

vfsgroup13:$(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4)
	gcc $(LDFFLAG) $(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4) -o ../bin/vfsgroup13

../bin/test.o:../include/mainHeader.h ../include/funcPrototype.h ../src/test.c
	gcc $(LDFFLAG) -c ../src/test.c -o ../bin/test.o

../bin/narrtest.o:../include/mainHeader.h ../src/narrtest.c
	gcc $(LDFFLAG) -c ../src/narrtest.c -o ../bin/narrtest.o

../bin/makeDir.o:../include/mainHeader.h ../src/makeDir.c
	gcc $(LDFFLAG) -c ../src/makeDir.c -o ../bin/makeDir.o

../bin/makeDirP.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/makeDirP.c
	gcc $(LDFFLAG) -c ../src/makeDirP.c -o ../bin/makeDirP.o

../bin/listDir.o:../include/mainHeader.h ../src/listDir.c
	gcc $(LDFFLAG) -c ../src/listDir.c -o ../bin/listDir.o

../bin/bstTree.o:../include/mainHeader.h ../include/funcPrototype.h ../src/bstTree.c
	gcc $(LDFFLAG) -c ../src/bstTree.c -o ../bin/bstTree.o

../bin/structhash1.o:../include/mainHeader.h ../src/structhash1.c
	gcc $(LDFFLAG) -c ../src/structhash1.c -o ../bin/structhash1.o

../bin/searchNary.o:../include/mainHeader.h ../src/searchNary.c
	gcc $(LDFFLAG) -c ../src/searchNary.c -o ../bin/searchNary.o

../bin/curPtrFunc1.o:../include/mainHeader.h ../include/funcPrototype3.h ../src/curPtrFunc1.c
	gcc $(LDFFLAG) -c ../src/curPtrFunc1.c -o ../bin/curPtrFunc1.o

../bin/searchFunc.o:../include/mainHeader.h ../src/searchFunc.c
	gcc $(LDFFLAG) -c ../src/searchFunc.c -o ../bin/searchFunc.o

../bin/stringtok.o:../include/mainHeader.h ../src/stringtok.c
	gcc $(LDFFLAG) -c ../src/stringtok.c -o ../bin/stringtok.o

../bin/deleteDir.o:../include/mainHeader.h ../include/funcPrototype2.h ../src/deleteDir.c
	gcc $(LDFFLAG) -c ../src/deleteDir.c -o ../bin/deleteDir.o

../bin/moveDir.o:../include/mainHeader.h ../include/funcPrototype2.h ../src/moveDir.c
	gcc $(LDFFLAG) -c ../src/moveDir.c -o ../bin/moveDir.o

../bin/addFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/addFile.c
	gcc $(LDFFLAG) -c ../src/addFile.c -o ../bin/addFile.o

../bin/listFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/listFile.c
	gcc $(LDFFLAG) -c ../src/listFile.c -o ../bin/listFile.o

../bin/updateFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/updateFile.c
	gcc $(LDFFLAG) -c ../src/updateFile.c -o ../bin/updateFile.o

../bin/removeFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/removeFile.c
	gcc $(LDFFLAG) -c ../src/removeFile.c -o ../bin/removeFile.o

../bin/moveFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/moveFile.c
	gcc $(LDFFLAG) -c ../src/moveFile.c -o ../bin/moveFile.o 

../bin/copyFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/copyFile.c
	gcc $(LDFFLAG) -c ../src/copyFile.c -o ../bin/copyFile.o 

../bin/exportFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/exportFile.c
	gcc $(LDFFLAG) -c ../src/exportFile.c -o ../bin/exportFile.o

../bin/unmountVfs.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/unmountVfs.c
	gcc $(LDFFLAG) -c ../src/unmountVfs.c -o ../bin/unmountVfs.o

../bin/errorCheck.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../include/funcPrototype3.h ../src/errorCheck.c
	gcc $(LDFFLAG) -c ../src/errorCheck.c -o ../bin/errorCheck.o

../bin/currPtrRet.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../src/currPtrRet.c
	gcc $(LDFFLAG) -c ../src/currPtrRet.c -o ../bin/currPtrRet.o

../bin/errorCheck1.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../include/funcPrototype3.h ../src/errorCheck1.c
	gcc $(LDFFLAG) -c ../src/errorCheck1.c -o ../bin/errorCheck1.o

../bin/manvfs.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../include/funcPrototype3.h ../src/manvfs.c
	gcc $(LDFFLAG) -c ../src/manvfs.c -o ../bin/manvfs.o


clean:
	rm ../bin/*.o 
	rm ../bin/vfsgroup13

