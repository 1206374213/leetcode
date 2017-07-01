bool isPalindrome(int x) {
    if(x<=9&&x>=0)
        return true;
    if(x<0)
        return false;
    int i=0;
    int temp=x;
    while((x/pow(10,i))>=10)
    i++;
    int j;
    int ans=0;
    for (j=0;j<=i;j++)
    {
        //if(i-j+1)
        ans+=(x%10)*pow(10,i-j);
        x=x/10;
    }
  
    return ans==temp;
    
    
}