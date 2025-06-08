/*
 * hello - A friendly greeting program
 *
 * A simple utility that greets users by name when provided as arguments,
 * or introduces the author when run without arguments.
 *
 * Author: RAJ ROY
 * Usage: hello [name...]
 */

//Just a simple program to print the name of the user;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    /* Check if any arguments are provided */
    if (argc > 1) {
        /* Print greeting with provided names */
        printf("Hello ");
        for (int i = 1; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
    } else {
        /* Print author introduction when no arguments provided */
        printf("I Think you Are Calling Me!\n");
        printf("My name is RAJ ROY\n");
    }
    return 0;
}
