int findComplement(int num) {
    
    int c=0,mask=0;
    if(num==0)
    {
        return 0;
    }
    int temp=num;
    while(temp>0)
    {
        mask= (mask<<1) |1;
        temp>>=1;
    }
    return mask^num;

    
}
