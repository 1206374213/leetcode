class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxp=-1;
        int result=0;
        int len=prices.size();
        if(len<=0)
            return 0;
        int minp=0x7fffffff;
        int min[len];
        int max[len];
        
        for(int i=0,j=prices.size()-1;i<prices.size(),j>=0;i++,j--)
        {
            if(minp>prices[i])
                minp=prices[i];
            if(maxp<prices[j])
                maxp=prices[j];
            min[i]=minp;
            max[j]=maxp;
        }
        for(int i=0;i<len;i++)
            if((max[i]-min[i])>result)
                result=max[i]-min[i];
        return result;
        
    }
};