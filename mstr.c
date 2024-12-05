int isNumber(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= '0' && text[index] <= '9')
            index++;
        else
            return 0;
    }
    return 1;
}

int isCapital(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= 'A' && text[index] <= 'Z')
            index++;
        else
            return 0;
    }
    return 1;
}

int isLetter(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= 'a' && text[index] <= 'z')
            index++;
        else
            return 0;
    }
    return 1;
}
