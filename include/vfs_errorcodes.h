/*
 * VFS Error codes
 * Last updated: 15-Nov-2012
 */
//New  (if the argument is not specified)
#define ERR_VFS_CREATE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_CREATE_01 "DATA_FILE_ALREADY_EXISTS"
#define ERR_VFS_CREATE_02 "CANNOT_CREATE_DATAFILE"

 // The slash (/) character is not allowed
#define ERR_VFS_CREATE_03 "INVALID_CHARACTER_IN_NAME"
// Valid range for size is 1 to 1024 (inclusive)
#define ERR_VFS_CREATE_04 "INVALID_SIZE"
//New   (If label name exceeds 30 characters)
#define ERR_VFS_CREATE_05 "VFS_LABEL_TOO_LARGE"

#define ERR_VFS_MOUNT_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_MOUNT_01 "DATA_FILE_NOT_FOUND"
#define ERR_VFS_MOUNT_02 "CANNOT_READ_FROM_FILE"
//New
#define ERR_VFS_MOUNT_03 "VFS_ALREADY_MOUNTED"

#define ERR_VFS_UNMOUNT_00 "VFS_INSUFFICIENT_ARGUMENTS"
// Use when fopen fails
#define ERR_VFS_UNMOUNT_01 "DATA_FILE_NOT_FOUND"
// Use when fwrite fails
#define ERR_VFS_UNMOUNT_02 "CANNOT_WRITE_TO_FILE"
//New
#define ERR_VFS_UNMOUNT_03 "VFS_NOT_MOUNTED"

#define ERR_VFS_MAKEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
//changed to FILESYSTEM_FULL from UNABLE_TO_CREATE_NEWDIR
#define ERR_VFS_MAKEDIR_01 "FILESYSTEM_FULL"
#define ERR_VFS_MAKEDIR_02 "INVALID_CHARACTER_IN_DIRNAME"
#define ERR_VFS_MAKEDIR_03 "DIRECTORY_ALREADY_EXISTS"
//New
#define ERR_VFS_MAKEDIR_05 "VFS_NOT_MOUNTED"

#define ERR_VFS_DELETEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_DELETEDIR_01 "CANNOT_FIND_SPECIFIED_DIR"
#define ERR_VFS_DELETEDIR_02 "DIRECTORY_IS_NOT_EMPTY"
//New
#define ERR_VFS_DELETEDIR_04 "VFS_NOT_MOUNTED"

#define ERR_VFS_MOVEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_MOVEDIR_01 "CANNOT_FIND_SPECIFIED_SOURCEDIR"
//(if specified dir is not there, it is not created in this case unlike in add dir)
#define ERR_VFS_MOVEDIR_02 "CANNOT_FIND_SPECIFIED_DESTINATIONDIR"
//New
#define ERR_VFS_MOVEDIR_04 "SOURCE_CANNOT_BE_FILE"
#define ERR_VFS_MOVEDIR_05 "DESTINATION_ALREADY_HAVE_SOURCE_DIR"
//New
#define ERR_VFS_MOVEDIR_06 "CANNOT_MOVE_PARENT_TO_CHILD_DIR"
//New
#define ERR_VFS_MOVEDIR_07 "DESTINATION_CANNOT_BE_FILE"
//New
#define ERR_VFS_MOVEDIR_08 "VFS_NOT_MOUNTED"

//New
#define ERR_VFS_LISTDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_LISTDIR_01 "CANNOT_FIND_SPECIFIED_PATH_OR_DIR"
#define ERR_VFS_LISTDIR_02 "INVALID_FLAG"
#define ERR_VFS_LISTDIR_03 "VFS_NOT_MOUNTED"
#define ERR_VFS_LISTDIR_04 "CANNOT_CREATE_OUTPUTFILE"

#define ERR_VFS_ADDFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_ADDFILE_02 "INVALID_CHARACTER_IN_FILENAME"
#define ERR_VFS_ADDFILE_03 "FILE_ALREADY_EXISTS"
#define ERR_VFS_ADDFILE_04 "FILE_SYSTEM_FULL"
//New
#define ERR_VFS_ADDFILE_05 "CANNOT_WRITE_TO_DATAFILE"
//New : (if data exceeds block size)
#define ERR_VFS_ADDFILE_06 "FILE_TOO_LARGE"
//New
#define ERR_VFS_ADDFILE_07 "VFS_NOT_MOUNTED"
#define ERR_VFS_ADDFILE_08 "SOURCE_FILE_NOT_FOUND"

#define ERR_VFS_LISTFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_LISTFILE_01 "SOURCE_FILE_PATH_NOT_FOUND"
#define ERR_VFS_LISTFILE_02 "NOT_A_TEXT_FILE"
//New
#define ERR_VFS_LISTFILE_03 "CANNOT_CREATE_OUTPUTFILE"
//New
#define ERR_VFS_LISTFILE_04 "VFS_NOT_MOUNTED"

#define ERR_VFS_UPDATEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_UPDATEFILE_01 "INTERNAL_FILE_NOT_FOUND"
#define ERR_VFS_UPDATEFILE_02 "EXTERNAL_FILE_NOT_FOUND"
//New
#define ERR_VFS_UPDATEFILE_03 "EXTERNAL_FILE_TOO_LARGE"
//New
#define ERR_VFS_UPDATEFILE_04 "VFS_NOT_MOUNTED"

#define ERR_VFS_REMOVEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
// Use this error even when the given argument is a directory and not a file
#define ERR_VFS_REMOVEFILE_01 "CANNOT_FIND_SPECIFIED_FILE"
//New
#define ERR_VFS_REMOVEFILE_02 "VFS_NOT_MOUNTED"

#define ERR_VFS_MOVEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_MOVEFILE_01 "CANNOT_FIND_SOURCEFILE"
#define ERR_VFS_MOVEFILE_02 "CANNOT_FIND_DESTINATION_PATH"
//New
#define ERR_VFS_MOVEFILE_06 "VFS_NOT_MOUNTED"

#define ERR_VFS_COPYFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_COPYFILE_01 "CANNOT_FIND_SOURCEFILE"
#define ERR_VFS_COPYFILE_02 "CANNOT_FIND_DESTINATIONPATH"
#define ERR_VFS_COPYFILE_03 "CANNOT_COPY_DIR_TO_FILE"
#define ERR_VFS_COPYFILE_04 "FILE_SYSTEM_FULL"
#define ERR_VFS_COPYFILE_05 "VFS_NOT_MOUNTED"

#define ERR_VFS_EXPORTFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
#define ERR_VFS_EXPORTFILE_01 "CANNOT_FIND_SOURCEFILE"
#define ERR_VFS_EXPORTFILE_02 "CANNOT_CREATE_OUTPUTFILE"
#define ERR_VFS_EXPORTFILE_03 "CANNOT_EXPORT_DIR"
//New
#define ERR_VFS_EXPORTFILE_04 "VFS_NOT_MOUNTED"

#define ERR_VFS_SEARCHFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
//New
#define ERR_VFS_SEARCHFILE_02 "VFS_NOT_MOUNTED"
