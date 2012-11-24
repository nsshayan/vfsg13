/*
 * File: vfsdriver.c
 *
 * Description: This is a driver program for testing your VFS system using an interaction script as input
 * You need to make additional calls to your respective functions as noted in the comments below
 * Make sure the output you display is exactly as per the given specifications for you. Do NOT print
 * any extra output (like debug messages) in the final version of your driver program. You can use this driver program
 * in a in incremental manner as you keep implementing one operator after another. For operators not yet implemented,
 * you can leave the output as given ("TO_BE_DONE"). So you can use this program as your "main" program for testing purposes.
 *
 * DO NOT write the full code for operators in the driver program! You must only CALL your functions from here.
 *
 * Usage: vfsdriver <scriptfilename>
 */

#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"
#include "funcPrototype3.h"

#define BUFSIZE 200
#define CMDSIZE 30
#define PARSIZE 100

void createvfs ( char *P1, int P2 );
void mountvfs ( char *P1 );
void unmountvfs ( char *P1 );
void makedir ( char *P1, char *P2 );
void deletedir ( char *P1 );
void movedir ( char *P1, char *P2 );
void listdir ( char *P1, int P2, char *P3 );
void addfile ( char *P1, char *P2, char *P3 );
void listfile ( char *P1, char *P2 );
void updatefile ( char *P1, char *P2 );
void removefile ( char *P1 );
void movefile ( char *P1, char *P2 );
void copyfile ( char *P1, char *P2 );
void exportfile ( char *P1, char *P2 );
void searchfile ( char *P1, char *P2 );

void processcommand( char *command, char *P1, char *P2, char *P3 );

int main( int argc, char *argv[] )
{
	FILE *scriptfp,*fp;
	char linebuffer[BUFSIZE];
	char command[CMDSIZE], par1[PARSIZE], par2[PARSIZE], par3[PARSIZE];
	char *token;
	char ch1[100]={},ch2[100]={};

	if( argc != 2 ){
		fprintf(stderr,"Usage: vfsdriver <scriptfile>\n");
		return(1);
	}

	if( (scriptfp=fopen(argv[1],"r")) == NULL ){ // changed here from argv[1] to scriptfile
		fprintf(stderr,"Unable to open script file: %s\n", argv[1]);
		return(2);
	}
	
	fp=fopen("../test/SUCCESS.txt","w");
	fclose(fp);
	while( fgets(linebuffer, sizeof(linebuffer), scriptfp) != NULL ){
		strcpy(ch1,"root");
		strcpy(ch2,"root");	
		/* This output is for debugging... do not uncomment in final version */
		/*
		printf("==================================================\n");
		printf("Processing: %s", linebuffer);
		printf("==================================================\n");
		*/

		/* Remove the extra newline character in the end of line */
		linebuffer[ strlen(linebuffer)-1 ] = '\0';
		
		/* Get the command and the parameters using tokenizer */
		strcpy( command, (token = strtok(linebuffer, " ")) == NULL ? "" : token );
		strcat(command,"\0");
		
		strcpy( par1, (token = strtok(NULL, " ")) == NULL ? "" : token );
		strcat(par1,"\0");
		strcpy( par2, (token = strtok(NULL, " ")) == NULL ? "" : token );
		if(abs(strcasecmp(par2,"")))
			strcat(par3,"\0");
		strcpy( par3, (token = strtok(NULL, " ")) == NULL ? "" : token );
		if(abs(strcasecmp(par3,"")))
			strcat(par3,"\0");
		 printf("Command:%s:p1:%s:p2:%s:p3:%s\n",command, par1, par2, par3); 
	
		if((strcmp(command,"createvfs")!=0)&&(strcmp(command,"mountvfs")!=0)
			&&(strcmp(command,"unmountvfs")!=0)&&(strcmp(command," ")!=0)&&(strcmp(command,"searchfile")!=0))
		{
			
			if(strlen(par1)==1)
				strcpy(par1,"root");
			else{	
					strcat(ch1,par1);
					
					strcpy(par1,ch1);}

			if((strcmp(command,"movedir")==0)||(strcmp(command,"movefile")==0)||(strcmp(command,"copyfile")==0)) 
			{
				if(strlen(par2)==1)
					strcpy(par2,"root");
				else{
					strcat(ch2,par2);
					strcpy(par2,ch2);	}			
			}
				
		}		
		 printf("Command:%s:p1:%s:p2:%s:p3:%s\n",command, par1, par2, par3); 
		processcommand( command, par1, par2, par3 );
	}
/*printf("\n printing the n-ary tree");
print(root);
printf("\n");

printf("\n The bst created is ::");
display(bstroot);

//printf("\n Search function using bst::\n");
//searchbst("root/automobile",bstroot);
//searchBstPath("root/transport",bstroot); */

return 0;
}

void processcommand( char *command, char *P1, char *P2, char *P3 )
{
	if( strcmp(command, "createvfs") == 0 ){
		int size = atoi(P2);
		createvfs (P1,size);
	}
	else if( strcmp(command, "mountvfs") == 0 )
		mountvfs (P1);
	else if( strcmp(command, "unmountvfs") == 0 )
		unmountvfs (P1);
	else if( strcmp(command, "makedir") == 0 )
		makedir (P1,P2);
	else if( strcmp(command, "deletedir") == 0 )
		deletedir (P1);
	else if( strcmp(command, "movedir") == 0 )
		movedir (P1,P2);
	else if( strcmp(command, "listdir") == 0 ){
		int flag = atoi(P2);
		listdir (P1,flag,P3);
	}
	else if( strcmp(command, "addfile") == 0 )
		addfile (P1,P2,P3);
	else if( strcmp(command, "listfile") == 0 )
		listfile (P1,P2);
	else if( strcmp(command, "updatefile") == 0 )
		updatefile (P1,P2);
	else if( strcmp(command, "removefile") == 0 )
		removefile (P1);
	else if( strcmp(command, "movefile") == 0 )
		movefile (P1,P2);
	else if( strcmp(command, "copyfile") == 0 )
		copyfile (P1,P2);
	else if( strcmp(command, "exportfile") == 0 )
		exportfile (P1,P2);
	else if( strcmp(command, "searchfile") == 0 )
		searchfile (P1,P2);
	else
		printf("Ignoring invalid command %s\n", command);
}

void createvfs ( char *P1, int P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //create_vfs(P1,P2);   
    errorCheck=error_createvfs(P1,P2);
    if(errorCheck==0) {
        create_vfs(P1,P2);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","w");
        fprintf(fp,"%s","createvfs_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
//    printf("createvfs_TO_BE_DONE\n");
}

void mountvfs ( char *P1 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */   
    //mount_vfs(P1);
    errorCheck=error_mountvfs(P1);
    if(errorCheck==0) {
        mount_vfs(P1);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","mountvfs_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    //printf("mountvfs_TO_BE_DONE\n");
}

void unmountvfs ( char *P1 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //unmount_vfs(P1);
    errorCheck=error_unmountvfs(P1);
    if(errorCheck==0) {
        unmount_vfs(P1);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","unmountvfs_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    //printf("unmountvfs_TO_BE_DONE\n");
}

void makedir ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //makeDirRec(P1,P2);
    errorCheck=error_makedir(P1,P2);
    if(errorCheck==0) {
        makeDirRec(P1,P2);  
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","makedir_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("\nmakedir_TO_BE_DONE\n");
}

void deletedir ( char *P1 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */   
    //deleteDir(P1);
    errorCheck=error_deletedir(P1);
    if(errorCheck==0) {
        deleteDir(P1);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","deletedir_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("deletedir_TO_BE_DONE\n");
}

void movedir ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //moveDir(P1,P2);
    errorCheck=error_movedir(P1,P2);
    if(errorCheck==0) {
        moveDir(P1,P2);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","movedir_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("movedir_TO_BE_DONE\n");
}

void listdir ( char *P1, int P2, char *P3 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
//    listDir(P1,P2,P3);
    errorCheck=error_listdir(P1,P2,P3);
    if(errorCheck==0) {
        listDir(P1,P2,P3);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","listdir_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("listdir_TO_BE_DONE\n");
}

void addfile ( char *P1, char *P2, char *P3 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //add_file(P1,P2,P3);
    errorCheck=error_addfile(P1,P2,P3);
    if(errorCheck==0) {
        add_file(P1,P2,P3);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","addfile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("addfile_TO_BE_DONE\n");
}

void listfile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */   
    //list_file(P1,P2);
    errorCheck=error_listfile(P1,P2);
    if(errorCheck==0) {
        list_file(P1,P2);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","listfile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }   
    printf("listfile_TO_BE_DONE\n");
}

void updatefile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //update_file(P1,P2);
    errorCheck=error_updatefile(P1,P2);
    if(errorCheck==0) {
        update_file(P1,P2);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","updatefile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }   
    printf("updatefile_TO_BE_DONE\n");
}

void removefile ( char *P1 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //remove_file(P1);
    errorCheck=error_removefile(P1);
    if(errorCheck==0) {
        remove_file(P1);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","removefile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("removefile_TO_BE_DONE\n");
}

void movefile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //move_file(P1,P2);
    errorCheck=error_movefile(P1,P2);
    if(errorCheck==0) {
        move_file(P1,P2);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","movefile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("movefile_TO_BE_DONE\n");
}

void copyfile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //copy_file(P1,P2);
    errorCheck=error_copyfile(P1,P2);
    if(errorCheck==0) {
        copy_file(P1,P2);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","copyfile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("copyfile_TO_BE_DONE\n");
}

void exportfile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //export_file(P1,P2);
    errorCheck=error_exportfile(P1,P2);
    if(errorCheck==0) {
        export_file(P1,P2);
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","exportfile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("exportfile_TO_BE_DONE\n");
}

void searchfile ( char *P1, char *P2 )
{
    /* Call the appropriate function with given arguments and display appropriate output on the screen */
    //search_file(P1,P2);
    errorCheck=error_searchfile(P1,P2);
    if(errorCheck==0) {
        search_file(P1,P2);   
        FILE *fp;
        fp=fopen("../test/SUCCESS.txt","a+");
        fprintf(fp,"%s","searchfile_success");
        fprintf(fp,"%c",'\n');
        fclose(fp);
    }
    printf("searchfile_TO_BE_DONE\n");
}

