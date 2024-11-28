int countBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    int ex_or = x^y;
    return countBits(ex_or);
}
