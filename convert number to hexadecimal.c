char * toHex(int num){
    if(!num){
        char* ret=(char *)malloc(2*sizeof(char));
        ret[0]='0';
        ret[1]='\0';
        return ret;
    }
    else{   
        char x[8];
        int Xidx=0;
        int dummy;
        while((num)&&( Xidx < 8)){
            dummy=((num) &(0xF));
            if(dummy<=9){
                x[Xidx]=dummy+0x30;
            }
            else{
                x[Xidx]=dummy+0x57;
            }
            Xidx++;
            num=num>>4;
        }
        char* ret=(char *)malloc((Xidx+1)*sizeof(char));
        for(int i=Xidx-1;i>=0;--i){
            printf("%c ",x[i]);
            ret[i]=x[Xidx-i-1];
        }
        ret[Xidx]='\0';
        return ret;
    }
}
