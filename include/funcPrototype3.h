extern int error_createvfs(char *,int );

extern int error_mountvfs(char *);

extern int error_unmountvfs(char *);

extern int error_makedir(char *,char *);

extern int error_deletedir(char *);

extern int error_movedir(char *, char *);

extern int error_listdir(char *, int , char *);

extern int error_addfile(char *, char *, char *);

extern int error_listfile(char *, char *);

extern int error_updatefile(char *, char *);

extern int error_removefile(char *);

extern int error_movefile(char *,char *);

extern int error_copyfile(char *,char *);

extern int error_exportfile(char *,char *);

extern int error_searchfile(char *,char *);

extern struct nAryTree *curPtrFunc1(char [],struct nAryTree *);

extern void man_vfs(char *);
