#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack_overflow(void)
{
    char buffer[10];
    int xyz = 0;

    printf("\nSTACK OVERFLOW\n");
    printf("A 10-byte character array was created on the stack.\n");
    printf("It can safely hold 9 characters and the null terminator.\n");
    printf("The key \"gainesville\" requires 12 bytes: 11 characters plus the null terminator.\n");
    printf("Entering this key writes 2 bytes past the end of the stack buffer.\n");
    printf("Those extra bytes could corrupt nearby variables or control information.\n");
    printf("Enter the key (use gainesville): ");

    /* Unsafe: input longer than 9 characters will overflow buffer. */
    scanf("%s", buffer);

    printf("The input was stored in the buffer as: %s\n", buffer);
    printf("The program may continue normally even though an overflow occurred.\n");
    printf("This is dangerous because memory corruption does not always cause an immediate crash.\n");

    if (strcmp(buffer, "gainesville") == 0)
    {
        printf("You entered the right key!\n");
        xyz = 1;
    }
    else
    {
        printf("You entered the wrong key!\n");
    }

    if (xyz)
    {
        printf("Access has been given to the user.\n");
    }
}

void heap_overflow(void)
{
    char *buffer;

    printf("\nHEAP OVERFLOW\n");

    buffer = malloc(10);

    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("The program allocated 10 bytes of memory on the heap.\n");
    printf("It will copy \"gainesville\" into that memory.\n");
    printf("The string requires 12 bytes: 11 characters plus the null terminator.\n");
    printf("Therefore, strcpy writes 2 bytes outside the allocated heap buffer.\n");
    printf("These extra bytes could corrupt another heap object or allocator information.\n");

    /* "gainesville" needs 12 bytes, but only 10 were allocated. */
    strcpy(buffer, "gainesville");

    printf("Data stored in heap buffer: %s\n", buffer);
    printf("The text may print correctly even though memory outside the allocation was overwritten.\n");

    free(buffer);
}

void integer_overflow(void)
{
    unsigned char number = 255;

    printf("\nINTEGER OVERFLOW\n");
    printf("An unsigned char normally stores values from 0 through 255.\n");
    printf("Number before overflow: %u\n", number);

    printf("The program adds 1 to 255. The mathematical result should be 256.\n");
    printf("However, 256 cannot be represented by an unsigned char.\n");

    number = number + 1;

    printf("Number after overflow: %u\n", number);
    printf("The value wrapped from 255 back to 0.\n");
    printf("In a real program, this could produce an incorrect size or security check.\n");
}

int main(void)
{
    heap_overflow();
    integer_overflow();
    stack_overflow();

    return 0;
}
