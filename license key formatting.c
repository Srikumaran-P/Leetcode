char convert(char c){
    if(c >= 'a' && c <= 'z')
        return c - 0x20;
    else
        return c;
}

char * licenseKeyFormatting(char * s, int k){
    int len = strlen(s), size = len + len / k + 1, counter = 0;
    char* ans = (char*)calloc(size, sizeof(char));
    ans[--size] = '\0';
    for(int i = len - 1; i >= 0; i--){
        if(s[i] == '-')
            continue;
        ans[--size] = convert(s[i]);
        counter++;
        if(counter == k && i != 0){
            ans[--size] = '-';
            counter = 0;
        }
    }
    /* no leading '-' */
    if(ans[size] == '-')
        size++;
    return ans + size;
}
