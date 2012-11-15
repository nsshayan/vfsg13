#define ERR_VFS_CREATE_01 "DATA_FILE_ALREADY_EXISTS"
#define ERR_VFS_CREATE_02 "CANNOT_CREATE_DATAFILE"
#define ERR_VFS_CREATE_03 "NOT_ENOUGH_MEMORY"
#define ERR_VFS_CREATE_04 "INVALID_CHARACTER_IN_NAME"
#define ERR_VFS_CREATE_05 "INVALID_SIZE"  

#define ERR_VFS_MOUNT_01 "DATA_FILE_NOT_FOUND"
#define ERR_VFS_MOUNT_02 "CANNOT_READ_FROM_FILE"
#define ERR_VFS_MOUNT_03 "INVALID_HEADER"

#define ERR_VFS_UNMOUNT_01 "DATA_FILE_NOT_FOUND"
#define ERR_VFS_UNMOUNT_02 "ACCESS_DENIED"
#define ERR_VFS_UNMOUNT_03 "CANNOT_WRITE_TO_FILE"

#define ERR_VFS_MAKEDIR_01 "UNABLE_TO_CREATE_NEWDIR"
#define ERR_VFS_MAKEDIR_02 "INVALID_CHARACTER_IN_DIRNAME"
#define ERR_VFS_MAKEDIR_03 "DIRECTORY_ALREADY_EXISTS"

#define ERR_VFS_DELETEDIR_01 "CANNOT_FIND_SPECIFIED_PATH_OR_DIR"
#define ERR_VFS_DELETEDIR_02 "DIRECTORY_IS_NOT_EMPTY"
#define ERR_VFS_DELETEDIR_03 "INVALID_DIRNAME"

#define ERR_VFS_MOVEDIR_01 "CANNOT_FIND_SPECIFIED_SOURCEDIR"
#define ERR_VFS_MOVEDIR_02 "CANNOT_FIND_SPECIFIED_DESTINATIONDIR"
#define ERR_VFS_MOVEDIR_03 "SOURCE_PATH_MISSING"
#define ERR_VFS_MOVEDIR_04 "DESTINATION_PATH_MISSING"
#define ERR_VFS_MOVEDIR_05 "DESTINATION_ALREADY_HAVE_SOURCE_DIR"

#define ERR_VFS_LISTDIR_01 "CANNOT_FIND_SPECIFIED_PATH_OR_DIR"
#define ERR_VFS_LISTDIR_02 "INVALID_FLAG"
#define ERR_VFS_LISTDIR_03 "CANNOT_FIND_OUTPUTFILE"

#define ERR_VFS_ADDFILE_01 "UNABLE_TO_CREATE_NEWFILE"
#define ERR_VFS_ADDFILE_02 "INVALID_CHARACTER_IN_FILENAME"
#define ERR_VFS_ADDFILE_03 "FILE_ALREADY_EXISTS"
#define ERR_VFS_ADDFILE_04 "FILE_SYSTEM_FULL"

#define ERR_VFS_LISTFILE_01 "SOURCE_FILE_PATH_NOT_FOUND"
#define ERR_VFS_LISTFILE_02 "OUTPUT_FILE_PATH_NOT_FOUND"
#define ERR_VFS_LISTFILE_03 "SOURCE_PATH_MISSING"
#define ERR_VFS_LISTFILE_04 "OUTPUT_PATH_MISSING"
#define ERR_VFS_LISTFILE_05 "NOT_A_TEXT_FILE"

#define ERR_VFS_UPDATEFILE_01 "SOURCE_FILE_PATH_NOT_FOUND"
#define ERR_VFS_UPDATEFILE_02 "DEST_FILE_PATH_NOT_FOUND"
#define ERR_VFS_UPDATEFILE_03 "INCORRECT_FILE_FORMAT"
#define ERR_VFS_UPDATEFILE_04 "FILE_SYSTEM_FULL"

#define ERR_VFS_REMOVEFILE_01 "CANNOT_FIND_SPECIFIED_PATH_OR_FILE"

#define ERR_VFS_MOVEFILE_01 "CANNOT_FIND_SPECIFIED_SOURCEFILE"
#define ERR_VFS_MOVEFILE_02 "CANNOT_FIND_SPECIFIED_DESTINATIONFILE"
#define ERR_VFS_MOVEFILE_03 "SOURCE_PATH_MISSING"
#define ERR_VFS_MOVEFILE_04 "DESTINATION_PATH_MISSING"

#define ERR_VFS_COPYFILE_01 "CANNOT_FIND_SPECIFIED_SOURCEFILE"
#define ERR_VFS_COPYFILE_02 "CANNOT_FIND_SPECIFIED_DESTINATIONFILE"
#define ERR_VFS_COPYFILE_03 "SOURCE_PATH_MISSING"
#define ERR_VFS_COPYFILE_04 "DESTINATION_PATH_MISSING"
#define ERR_VFS_COPYFILE_05 "CANNOT_COPY_DIR_TO_FILE"
#define ERR_VFS_COPYFILE_06 "FILE_SYSTEM_FULL"

#define ERR_VFS_EXPORTFILE_01 "CANNOT_FIND_SPECIFIED_SOURCEFILE"
#define ERR_VFS_EXPORTFILE_02 "CANNOT_FIND_SPECIFIED_OUTPUTFILE"
#define ERR_VFS_EXPORTFILE_03 "SOURCE_PATH_MISSING"
#define ERR_VFS_EXPORTFILE_04 "OUTPUT_PATH_MISSING"
#define ERR_VFS_EXPORTFILE_05 "OUTPUT_FILE_ALREADY_EXISTS"
#define ERR_VFS_EXPORTFILE_06 "CANNOT_EXPORT_DIR"

#define ERR_VFS_SEARCHFILE_01 "CANNOT_FIND_SPECIFIED_OUTPUTFILE"
#define ERR_VFS_SEARCHFILE_02 "OUTPUT_PATH_MISSING"

