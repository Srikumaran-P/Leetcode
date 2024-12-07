int findLUSlength(char* a, char* b) {
if(strcmp(a,b)==0)
{
    return -1;
}
int ans = -1, len1 = strlen(a), len2 = strlen(b);    

if(len1!=len2)
{
    if(len1 > len2)
    {
        return len1;
    }
    return len2;
}

for(int i = 0 ; i < len1 ; i++)
{
    for(int j = i ; j < len1 ; j++)
    {
        char temp[105];
        int o = 0;
        for(int k = i ; k <= j ; k++)
        {
            temp[o] = a[k];
            o++;
        }
        temp[o] = '\0';
        for(int k = 0 ; k < len2 ; k++)
        {        
            int jvrc = 0, f = 0;
            for(int l = 0 ; l < o ; l++)
            {
                if(b[k+l] == '\0')
                {
                    f++;
                    break;
                }
                else
                {
                    if(b[k+l] != temp[l])
                    {
                        jvrc++;
                    }
                   if(jvrc == 1)
                   {
                        break;
                   }
                }
            }
            if(f)
            {
                break;
            }
            if(jvrc == 1 && o > ans)
            {
                ans = o;
            }

        }
    }
}


return ans;

}
