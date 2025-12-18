#include <stdio.h>
#include <string.h>

void vulnerabla_function() {
    char buffer[10];        // buffer is hit
    printf("Put your name: ");
    gets(buffer);
    printf("Hello %s!\n", buffer);
}

int main() {
    vulnerabla_function();
    return 0;
}