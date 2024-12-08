bool checkRecord(char* s) {
    int a=0,l=0,i=0;
    while(s[i] != '\0'){
        if(s[i] == 'A')
            a++;
        if(s[i] == 'L' && s[i+1] == 'L')
            l++;
        else if(s[i+1] != '\0')
            l=0;
        
        i++;
        if(a>=2 || l >= 2 )
            return false;
    }

    return true;
}
