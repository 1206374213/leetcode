// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
int lengthOfLongestSubstring(char* s) {
    int i=0;
    int j;
    int flag[1024]={0};
    char ptr[1024];
    int index=0;
    int deviation=0;
   // int maxindex=0;
    int maxdeviation=0;
    while(s[i]!='\0')
    {
        for(j=0;j<1024;j++)
          flag[j]=0;
          index=i;
          deviation=0;
       // flag[s[i]='a']=1;
        for(j=i;s[j]!='\0'&&!flag[s[j]];j++)
        {
            flag[s[j]]=1;
            deviation++;
        }
        if(deviation>maxdeviation)
        {
            maxdeviation=deviation;
        //    maxindex=index;
        }
        i++;
    }
    
    
return maxdeviation;
    
}