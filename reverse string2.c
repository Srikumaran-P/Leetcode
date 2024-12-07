void reverse(char*s , int start,int end)
{
    while(start<end)
    {
        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
}


char* reverseStr(char* s, int k) {
    int n=strlen(s);
    for(int i=0;i<n;i+=2*k)
    {
        int end=(i + k - 1 < n) ? i + k - 1 : n - 1;
        reverse(s,i,end);
        
    }
    return s;
}
