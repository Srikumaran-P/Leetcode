void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void sort_arr(char *s, int len){
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++)
        {
            if(s[i] > s[j]){
                swap(&s[i], &s[j]);
            }
        }
    }
}

char findTheDifference(char* s, char* t) {
    int len = strlen(s);
    sort_arr(t,strlen(t));
    sort_arr(s,strlen(s));
    for(int i=0; i < len; i++){
        if(s[i] != t[i]){
            return t[i];
        }
    }
    return t[len];
}
