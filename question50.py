double myPow(double x, int n) {
       if(n==0)return 1;
       if(abs(n)%2==1)
       {
           if(n<0)
       return 1/(x*myPow(x*x,-(n+1)/2));
       else return x*myPow(x*x,n/2);
       }
       else
       {
           if(n<0)
           return 1/(x*x*myPow(x*x,-(n+2)/2));
           else
           return myPow(x*x,n/2);
       }
     

}