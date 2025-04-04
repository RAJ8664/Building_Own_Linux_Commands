/*
 * fileinfo - Display detailed information about a file
 *
 * This utility provides comprehensive information about a specified file,
 * including permissions, ownership, timestamps, and other metadata.
 *
 * Author: RAJ ROY
 * Usage: fileinfo <filename>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]) { 
    if (argc == 2) {
        struct stat current_file;
        if (stat(argv[1], &current_file) == -1) {
            perror("File Not Found:\n");
            exit(EXIT_FAILURE);
        }

        /* Display basic file information */
        printf("File Information:\n");
        printf("\n");
        
        printf("Name: %s\n", argv[1]);
        printf("UID: %d\n", current_file.st_uid);
        printf("GID: %d\n", current_file.st_gid);
        printf("Block Size: %ld\n", current_file.st_blksize);
        printf("Number Of Blocks: %ld\n", current_file.st_blocks);
        printf("Number Of Nlink: %ld\n", current_file.st_nlink);
        printf("\n");

        /* Display timestamp information */
        printf("Last Accessed Time: %s", ctime(&current_file.st_atime));
        printf("Last Modification Time: %s", ctime(&current_file.st_mtime));
        printf("Last Status Change Time: %s", ctime(&current_file.st_ctime));

        /* Display file permissions in rwx format */
        printf("File Permissions:\n");
        printf("\n");

        /* Owner permissions */
        printf((current_file.st_mode & S_IRUSR) ? "r" : "-");
        printf((current_file.st_mode & S_IWUSR) ? "w" : "-");
        printf((current_file.st_mode & S_IXUSR) ? "x" : "-");

        /* Group permissions */
        printf((current_file.st_mode & S_IRGRP) ? "r" : "-");
        printf((current_file.st_mode & S_IWGRP) ? "w" : "-");
        printf((current_file.st_mode & S_IXUSR) ? "x" : "-");
    
        /* Other permissions */
        printf((current_file.st_mode & S_IROTH) ? "r" : "-");
        printf((current_file.st_mode & S_IWOTH) ? "w" : "-");
        printf((current_file.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");
    }
    else {
        printf("Usage: fileinfo <filename>\n");
    }
    return 0;
}