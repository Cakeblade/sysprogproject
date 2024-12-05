#include <stdio.h>
#include "mstr.h"

#define MAXLEN 512

int main()
{
    int len;
    char text[MAXLEN];

    while (1)
    {
        printf("Please input text : ");
        while (scanf("%511s", text) == -1)
            printf("text input error\n");

        while (1)
        {
            printf("Which would you like to check?\n");
            printf("0. Exit\n");
            printf("1. Check for it's a numbers\n");
            printf("2. Check for it's all capitalized\n");
            printf("3. Check for it's all characters\n");
            scanf("%1d", &len);
            switch (len)
            {
                case 0:
                    return 0;
                case 1:
                    if (isNumber(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                case 2:
                    if (isCapital(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                case 3:
                    if (isLetter(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                default:
                    printf("Please re-select number.\n");
            }
        }

        return 0;
    }
}
