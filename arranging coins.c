int arrangeCoins(int n) {
 long long coins=0;
 int count=0, i=1;

 while(coins+i<=n)
 {
    coins+=i;
    i++;
    count+=1;
 }   

 return count;
}
