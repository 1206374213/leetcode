int reverse(int x)
{
    int flag;
    int i=0;
    int j=0;
    double newX=0;
    flag=x>0?1:0;
    if(x==0||x<INT_MIN||x>INT_MAX)return 0;
  //  if(x<9&&x>-9)return x;
    switch(flag)
    {
        case 0:
        x=-x;
        case 1:
        while(x>=pow(10,i))i++;
        i--; //printf("%d",i);
      //  for(j=0;j<i;j++)
        while(x!=0)
        {

            newX+=(double)(x%10)*pow(10,i-j);
            x=(x-x%10)/10;
            j++;
          //  printf("%d",newX);
        }
        break;
    }
   if((int)newX<0)return 0;
   return flag>0?newX:-newX;
}