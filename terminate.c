/*Author : RAJ ROY*/
/*
    Command terminates a process by name.
    Currently it works for most of the common programs, but not sure about the rest.
    Make sure to check the name of the process in the task manager before using the command --> terminate <process_name>
    The Process Name May differ from the name of the executable file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <sched.h>

#define PROC_DIR "/proc"
#define COMM_FILE "comm"

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}
void kill_by_name(const char *name) {
    DIR *proc_dir = opendir(PROC_DIR);
    if (!proc_dir) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (!is_numeric(entry->d_name)) continue;
        char comm_path[256];
        snprintf(comm_path, sizeof(comm_path), "%s/%s/%s", PROC_DIR, entry->d_name, COMM_FILE);
        FILE *comm_file = fopen(comm_path, "r");
        if (!comm_file) continue;
        char process_name[256];
        if (fgets(process_name, sizeof(process_name), comm_file)) {
            process_name[strcspn(process_name, "\n")] = '\0';
            if (strcmp(process_name, name) == 0) {
                pid_t pid = atoi(entry->d_name);
                if (kill(pid, SIGKILL) == 0) printf("Killed process: %s (PID: %d)\n", name, pid); 
                else perror("kill"); 
            }
        }
        fclose(comm_file);
    }
    closedir(proc_dir);
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: terminate <process_name>\n");
        return 1;
    }
    const char *process_name = argv[1];
    kill_by_name(process_name);
    return 0;
}