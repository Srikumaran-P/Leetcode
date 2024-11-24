bool isAnagram(char* s, char* t) {
    int index[128] = {0};

    if(strlen(s) != strlen(t))
        return false;

    for(int i=0;i<strlen(s);i++)
    {
        index[s[i]]++;
        index[t[i]]--;
    }

    for(int i=0;i<128;i++)
    {
        if(index[i] != 0)
            return false;
    }

    return true;
}
