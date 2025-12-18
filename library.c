#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];

    printf("Put your name: ");
    gets(buffer);

    printf("Hello %s!\n", buffer);

    return 0;
}