extern char **stringtok(char *);

extern void deleteDir(char []);

extern int countSlash(char *);

extern struct nAryTree *curPtrFuncName(char [],struct nAryTree *);

extern void moveDir(char [],char []);

extern void changeFullPath(struct nAryTree *,char []);

extern void add_file ( char *, char *, char *);

extern void list_file(char *,char *);

extern void update_file(char *,char *);

extern void remove_file(char *);

extern void export_file ( char *, char * );

extern void unmount_vfs(char *);

extern void move_file(char *,char *);

extern void traverse(struct nAryTree *);

extern void copy_file(char *,char *);

extern void makeDirRec(char *,char *);

extern struct nAryTree * currPtrReturn(char [],char []);

extern int error_createvfs(char *,int);

extern int error_mountvfs(char *);

extern int error_unmountvfs(char *);
