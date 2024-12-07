bool isAllUpper(char* word)
{
    int i=0;
    while(word[i]!='\0')
    {
        if(word[i]>96)
        return false;
        i++;
    }
    return true;
}
bool isAllLower(char* word)
{
    int i=1;
    while(word[i]!='\0')
    {
        if(word[i]<91)
        return false;
        i++;
    }
    return true;
}
bool detectCapitalUse(char* word) {
     return isAllUpper(word) || isAllLower(word);
}
