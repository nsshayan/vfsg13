extern struct nAryTree *createRoot(struct fileDescriptor *);

void makeDir(char * ,char *);

extern void print(struct nAryTree *);

extern void create_vfs(char *,int );

extern struct nAryTree *mount_vfs(char *);

extern void nTreeChild(struct fileDescriptor *);

extern void listDir(char *, int, char *);

extern struct nAryTree *curPtrFunc(char *,struct nAryTree *);

extern void listNonRec(struct nAryTree *);

extern void listRec(struct nAryTree *);

extern void deletebst(node *,char []);

extern int searchbst(char *,node *);

extern node* bstinsert(node* ,struct fileDescriptor *);

extern node* add(struct fileDescriptor *);

extern void display(node *);

extern void search(char *);

extern void hashing(struct fileDescriptor *);

extern list* hashadd(char *,char *, list *);

extern void addToFile(char []);

extern int searchBstPath(char [],node *);

extern llist *listinsert(llist *, char []);
