void reverse(char *s, int start, int end)
{
    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++, end--;
    }
}
char* reverseWords(char* s) {
    int i = 0, j = 0;
    while(s[i] != '\0')
    {
        while(s[i] == ' ' || s[i] == '\t')  i++;

        j = i;

        //get a word
        while(s[j] != ' ' && s[j] != '\t' && s[j] != '\0')  j++;

        //reverse the string
        reverse(s, i, j - 1);

        i = j;
    }
    return s;
}
