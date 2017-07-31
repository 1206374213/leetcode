typedef struct value
{
    int tol=0;
    int cur=0;
}val;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        map<string,val> smap;
        initMap(smap,words);
        int wordLength=words[0].size();
        int length=s.size()-wordLength*words.size()+1;
        int i=0,j=0;
        while(i<length)
        {
            j=i;
            while(!check(smap))
            {
                string str=s.substr(j,wordLength);
                //cout<<str<<endl;
                if(smap.count(str)>0&&smap[str].cur<smap[str].tol)
                {
                    smap[str].cur++;
                    j+=wordLength;
                }
                    
                else
                    break;
                    
            }
            if(check(smap))
                v.push_back(i);
                i++;
                reset(smap);
                         
        }
        return v;
    }
    bool check(map<string,val> smap)
    {
        for(map<string,val>::iterator it =smap.begin();it!=smap.end();it++)
            if(it->second.cur<it->second.tol)
                return false;
        return true;
    }
    void initMap(map<string,val>& smap,vector<string>& words){
        vector<string>::iterator iter=words.begin();
        while(iter!=words.end()){
            val temp;
            if(smap.count(*iter)==0)
            {
                temp.tol++;
                smap[*iter]=temp;
            }
            else
            {
                smap[*iter].tol++;
            }
            iter++;
                
        }
        map<string,val>:: iterator it;
       // for(it=smap.begin();it!=smap.end();it++)
            
       // cout<<it->first<<","<<it->second.tol<<endl;
    }
    void reset(map<string,val> &smap)
    {
        for(map<string,val>::iterator it=smap.begin();it!=smap.end();it++)
            it->second.cur=0;
    }
    
};