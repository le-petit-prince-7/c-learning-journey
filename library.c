#include <stdio.h>
#include <string.h>

/*int main() {
    char buffer[10];

    printf("Put your name: ");
    gets(buffer);

    printf("Hello %s!\n", buffer);

    return 0;
} */

int main() {
    char buffer[10];        // Buffer for 10 characters

    printf("Fill in your name: ");
    fgets(buffer, sizeof(buffer), stdin);  // Safe - reads max 9 chars + \0

    printf("Hello %s!\n", buffer);

    return 0;

}