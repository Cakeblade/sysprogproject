int isNumber(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= 48 && text[index] <= 57)
            index++;
        else
            return 0;
    }
    return 1;
}

int hasCapital(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= 65 && text[index] <= 90)
            return 1;
        else
            index++;
    }
    return 0;
}

int hasLetter(const char* text)
{
    int index = 0;
    if (text[index] == '\0')
        return 0;
    while (text[index] != '\0')
    {
        if (text[index] >= 97 && text[index] <= 122)
            return 1;
        else
            index++;
    }
    return 0;
}
