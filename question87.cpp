Scramble String
class Solution {
public:
    bool isScramble(string s1, string s2) {
       // return judge(s1,s2,0,s1.size()-1,0,s2.size()-1);
        if(s1.length()!=s2.length())
            return false;
        //if(s1.)
        bool dp[s1.length()][s2.length()][s1.length()+1]={false};
        //bool dp[s1.length()][s2.length()][s1.length()+1];
        for (int i=0;i<s1.length();i++)
            for(int j=0;j<s2.length();j++)
            {
                dp[i][j][1]=(s1[i]==s2[j]);
               // dp[i][j][0]=true;
            }
                
        for(int len=2;len<s1.length()+1;len++)
            for(int i=0;i<s1.length()-len+1;i++)
                for(int j=0;j<s2.length()-len+1;j++)
                {
                    dp[i][j][len]=false;
                     for(int k=1;k<len;k++)
                    {
                       dp[i][j][len]|=(dp[i][j][k]&&dp[i+k][j+k][len-k])||(dp[i+k][j][len-k]&&dp[i][j+len-k][k]); 
                    }
                }
                   
                        
        return dp[0][0][s1.length()];
    }
};