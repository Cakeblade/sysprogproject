#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define MAXLEN 512

int main()
{
    int len;
    char text[MAXLEN];
    void* handle;
    char* error;
    int (*isNumber)(const char*);
    int (*hasCapital)(const char*);
    int (*hasLetter)(const char*);

    handle = dlopen("./libmstr.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    isNumber = dlsym(handle, "isNumber");
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    hasCapital = dlsym(handle, "hasCapital");
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    hasLetter = dlsym(handle, "hasLetter");
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

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
                    if (dlclose(handle) < 0)
                    {
                        fprintf(stderr, "%s\n", dlerror());
                        exit(1);
                    }
                    return 0;
                case 1:
                    if (isNumber(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                case 2:
                    if (hasCapital(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                case 3:
                    if (hasLetter(text))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    break;
                default:
                    printf("Please re-select number.\n");
            }
        }

        if (dlclose(handle) < 0)
        {
            fprintf(stderr, "%s\n", dlerror());
            exit(1);
        }
        return 0;
    }
}
