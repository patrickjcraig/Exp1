#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[10];
    int xyz = 0;

    printf("\n Enter the key: \n");
    gets(buffer);

    if(strcmp(buffer, "gainesville"))
    {
        printf ("\n You entered the Wrong key!\n");
    }
    else
    {
        printf ("\n You entered the Right key!\n");
        xyz = 1;
    }

    if(xyz)
    {
        printf ("\n Congrats! Access has been given to user.\n");
    }

    return 0;
}
