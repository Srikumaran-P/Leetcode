/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int setBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int* countBits(int n, int* returnSize) {
    int *res = (int*)calloc(n+1,sizeof(int));
    *returnSize = n+1;
    for(int i=0; i<=n; i++)
    {
        res[i] = setBits(i);
    }
    return res;
}
