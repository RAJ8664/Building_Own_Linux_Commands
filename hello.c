/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Hello ");
        for (int i = 1; i < argc; i++) printf("%s", argv[i]);
        printf("\n");
    }
    else {
        printf("I Think you Are Calling Me!\n");
        printf("My name is RAJ ROY\n");
    }
    return 0;
}