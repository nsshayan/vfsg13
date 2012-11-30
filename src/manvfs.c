#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"
#include "funcPrototype3.h"

void man_vfs(char *P4)
{
	char command[20];
	strcpy(command,P4);
	if(!(strcmp(command,"createvfs"))){
		printf("\nNAME \n \tcreatevfs\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid createvfs ( char *P1, int P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tcreatevfs (vfs_label,size)–It create a Virtual File System.\n \t<vfs_label> is the name ofVFS. Size specified in kilobytes. Valid range is 1 to 1024 (inclusive)\n");
	}
	else if(!(strcmp(command,"mountvfs"))){
		printf("\nNAME \n \tmountvfs\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid mountvfs ( char *P1 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tmountvfs (vfs_label) – It Mount the VFS path on current directory.\n \t This involves loading the file/directory descriptors into various data structures used\n");
	}
	else if(!(strcmp(command,"unmountvfs"))){
		printf("\nNAME \n \tunmountvfs\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid unmountvfs ( char *P1 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tunmountvfs (vfs_label) -It unmount the VFS.\n \t It involves saving index information and tree information back into the hard disk.\n");
	}
	else if(!(strcmp(command,"makedir"))){
		printf("\nNAME \n \tmakedir\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid makedir ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tmakedir (parent_path, dir_name) – It create a new directory whose name should be<dir_name> in path specified by <parent_path>\n \t where '/' is considered as 'root'directory.\n");
	}
	else if(!(strcmp(command,"deletedir"))){
		printf("\nNAME \n \tdeletedir\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid deletedir ( char *P1 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tdeletedir (path) – To remove a file or a directory as indicated by < name>\n");
	}
	else if(!(strcmp(command,"movedir"))){
		printf("\nNAME \n \tmovedir\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid movedir ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tmovedir (source_dir_path,dest_dir_path) – It move a sub-tree <source_dir_path> to\n \t <dest_dir_path> directory.\n");
	}
	else if(!(strcmp(command,"listdir"))){
		printf("\nNAME \n \tlistdir\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid listdir ( char *P1, int P2, char *P3 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tlistdir (dir_name,flag, outputfile) – It list all the contents according to <flag> of the\n \t current directory i.e. specified by <dir_name>. Flag “-R” means recursive listing of the\n \t entire subtree. The output of listdir is saved in outputfile in the hard-disk \n");
	}
	else if(!(strcmp(command,"addfile"))){
		printf("\nNAME \n \taddfile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid addfile ( char *P1, char *P2, char *P3 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \taddfile (dest_dir_name, file_name, data) - It create a new file named <file_name> with\n \t <data> as content. in path specified by <dest_dir_name>. “data” corresponds to an\n \t external file residing in the hard disk.\n");
	}
	else if(!(strcmp(command,"listfile"))){
		printf("\nNAME \n \tlistfile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid listfile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tlistfile (file_path, output_file) - It extract the contents of a file specified by <file_path>\n \t and store in output file.\n");
	}
	else if(!(strcmp(command,"updatefile"))){
		printf("\nNAME \n \tupdatefile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid updatefile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tupdatefile (file_path, data) – It update/Edit the contents of a file specified by <file_path>\n \t with <data>.\n");
	}
	else if(!(strcmp(command,"removefile"))){
		printf("\nNAME \n \tremovefile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid removefile ( char *P1 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tremovefile (file_path) – It remove a file specified by <file_path>.\n");
	}
	else if(!(strcmp(command,"movefile"))){
		printf("\nNAME \n \tmovefile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid movefile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tmovefile(source_file_path,dest_file_path) – It rename <source_file_path> to\n \t <dest_file_path> file. The destination includes full file path including file name.\n \t Overwrite the destination file if it already exists.\n");
	}
	else if(!(strcmp(command,"copyfile"))){
		printf("\nNAME \n \tcopyfile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid copyfile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tcopyfile ( source_file_path,dest_file_path) – It to copy source file to destination\n \t specified. The destination includes full file path including file name. Overwrite the\n \t destination file if it already exists.\n");
	}
	else if(!(strcmp(command,"exportfile"))){
		printf("\nNAME \n \texportfile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid exportfile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \texportfile (vfs_file_path, hard_disk_path) – It export the file from the file system into\n \t the hard disk\n");
	}
	else if(!(strcmp(command,"searchfile"))){
		printf("\nNAME \n \tsearchfile\n");
		printf("\nSYNOPSIS\n \t#include <mainHeader.h>  #include <funcPrototype.h>   #include <funcPrototype2.h>   #include <funcPrototype3.h> \n");
		printf("\n \tvoid searchfile ( char *P1, char *P2 );\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tsearchfile (name, outputfile) – Retrieves the full path of all the files/folders having the\n \t given name as part of its at the beginning of file/folder name. The output is\n \t stored in outputfile.\n");
	}
	else if(!(strcmp(command,"man"))){
		printf("\nNAME \n \tman\n");
		printf("\nSYNOPSIS\n");
		printf("\nDESCRIPTION\n");
		printf("\n \tman(command name) - It is an interface to the off-line reference manuals.\n \t It describes the function briefly.\n");
	}
	else
		printf("Invalid Command Entered");
}













