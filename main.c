#include <stdio.h>


int main()
{
    char in = 1;
    while (in != 'D')
    {
        scanf(" %c", &in);
        switch (in)
        {
        case 'A':
            fun1();
            break;

        case 'B':
            fun2();
            break;

        case 'C':
            fun3();
            break;

        case 'D':
            break;

        // command doesn't match any case constant A, B, C, D
        default:
            printf("Error! command isn't correct \n");
        }
    }
    return 0;
}