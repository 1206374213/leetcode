int myAtoi(char* str) {
    int i=0;
    bool number=false;
    int j=0;
    bool check=false;
    while(str[i]!='\0')
    {
        if(str[i]=='+'||str[i]=='-')
        {
            i++;
            check=true;
            continue;
        }   
        if(!number)
        {
            while(!check&&str[i]==' ')i++;
            if(str[i]<='9'&&str[i]>='0')
            {
                number=true;
                i++;
            }
            else if((str[i]=='+'||str[i]=='-')||!check)
            {;
                check=true;
                i++;            
            }
            else
                return 0;
        }
        while(str[i]<='9'&&str[i]>='0')i++;
        break;
    }
       
    if(i==0)
        return 0;
    i--;
    int ans=0;
    int max;
    bool first=true;
    bool minus=false;
    while(j<=i)
    {
        if(str[j]==' ')
        {
            j++;
            continue;
        }
        if(first)
        {
            if(str[j]=='-')
            {
                minus=true;
                max=-2147483648;
                j++;
            }
            else if(str[j]=='+')
            {
                max=2147483647;
                minus=false;
                j++;
            }
            else
            {
                max=2147483647;
                minus=false;
            }
            first=false;
        }
        else
        {
            if(str[j]>='0'&&str[j]<='9')
        {
                if(minus)
                {
            if(max-ans<=0-(str[j]-'0')*pow(10,i-j))
                ans+=0-(str[j]-'0')*pow(10,i-j);
            else
                return INT_MIN;
                }
                else
                {
            if(max-ans>=(str[j]-'0')*pow(10,i-j))
                ans+=(str[j]-'0')*pow(10,i-j);
            else
                return INT_MAX;                   
                }

        }   
            else
                return 0;
            j++;
        }
    }
       return ans;
}