OBJECTS1 = ../bin/vfsdriver.o ../bin/test.o ../bin/narrtest.o ../bin/makeDir.o  ../bin/listDir.o ../bin/bstTree.o ../bin/structhash1.o 
OBJECTS2 = ../bin/searchNary.o ../bin/searchFunc.o ../bin/stringtok.o ../bin/deleteDir.o ../bin/moveDir.o ../bin/addFile.o ../bin/listFile.o
OBJECTS3 = ../bin/updateFile.o ../bin/removeFile.o ../bin/exportFile.o ../bin/moveFile.o ../bin/copyFile.o ../bin/unmountVfs.o 
OBJECTS4 = ../bin/errorCheck.o ../bin/currPtrRet.o ../bin/makeDirP.o

LDFFLAG = -g -Wall -I ../include/ 

../bin/newfile:$(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4)
	gcc $(LDFFLAG) $(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4) -o ../bin/newfile

../bin/vfsdriver.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h vfsdriver.c
	gcc $(LDFFLAG) -c vfsdriver.c  -o ../bin/vfsdriver.o

../bin/test.o:../include/mainHeader.h ../include/funcPrototype.h test.c
	gcc $(LDFFLAG) -c test.c -o ../bin/test.o

../bin/narrtest.o:../include/mainHeader.h narrtest.c
	gcc $(LDFFLAG) -c narrtest.c -o ../bin/narrtest.o

../bin/makeDir.o:../include/mainHeader.h makeDir.c
	gcc $(LDFFLAG) -c makeDir.c -o ../bin/makeDir.o

../bin/makeDirP.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h makeDirP.c
	gcc $(LDFFLAG) -c makeDirP.c -o ../bin/makeDirP.o

../bin/listDir.o:../include/mainHeader.h listDir.c
	gcc $(LDFFLAG) -c listDir.c -o ../bin/listDir.o

../bin/bstTree.o:../include/mainHeader.h ../include/funcPrototype.h bstTree.c
	gcc $(LDFFLAG) -c bstTree.c -o ../bin/bstTree.o

../bin/structhash1.o:../include/mainHeader.h structhash1.c
	gcc $(LDFFLAG) -c structhash1.c -o ../bin/structhash1.o

../bin/searchNary.o:../include/mainHeader.h searchNary.c
	gcc $(LDFFLAG) -c searchNary.c -o ../bin/searchNary.o

../bin/searchFunc.o:../include/mainHeader.h searchFunc.c
	gcc $(LDFFLAG) -c searchFunc.c -o ../bin/searchFunc.o

../bin/stringtok.o:../include/mainHeader.h stringtok.c
	gcc $(LDFFLAG) -c stringtok.c -o ../bin/stringtok.o

../bin/deleteDir.o:../include/mainHeader.h ../include/funcPrototype2.h deleteDir.c
	gcc $(LDFFLAG) -c deleteDir.c -o ../bin/deleteDir.o

../bin/moveDir.o:../include/mainHeader.h ../include/funcPrototype2.h moveDir.c
	gcc $(LDFFLAG) -c moveDir.c -o ../bin/moveDir.o

../bin/addFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h addFile.c
	gcc $(LDFFLAG) -c addFile.c -o ../bin/addFile.o

../bin/listFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h ../include/vfs_errorcodes.h listFile.c
	gcc $(LDFFLAG) -c listFile.c -o ../bin/listFile.o

../bin/updateFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h updateFile.c
	gcc $(LDFFLAG) -c updateFile.c -o ../bin/updateFile.o

../bin/removeFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h removeFile.c
	gcc $(LDFFLAG) -c removeFile.c -o ../bin/removeFile.o

../bin/moveFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h moveFile.c
	gcc $(LDFFLAG) -c moveFile.c -o ../bin/moveFile.o 

../bin/copyFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h copyFile.c
	gcc $(LDFFLAG) -c copyFile.c -o ../bin/copyFile.o 

../bin/exportFile.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h exportFile.c
	gcc $(LDFFLAG) -c exportFile.c -o ../bin/exportFile.o

../bin/unmountVfs.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h unmountVfs.c
	gcc $(LDFFLAG) -c unmountVfs.c -o ../bin/unmountVfs.o

../bin/errorCheck.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h errorCheck.c
	gcc $(LDFFLAG) -c errorCheck.c -o ../bin/errorCheck.o

../bin/currPtrRet.o:../include/mainHeader.h ../include/funcPrototype.h ../include/funcPrototype2.h currPtrRet.c
	gcc $(LDFFLAG) -c currPtrRet.c -o ../bin/currPtrRet.o

clean:
	rm ../bin/*.o 
	rm ../bin/newfile

