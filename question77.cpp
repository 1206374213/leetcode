class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        getRes(res,temp,k,1,n);
        return res;
     }
    void getRes(vector<vector<int>> &res,vector<int> &temp,int k,int from,int n)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }
        for(int j=from;j<=n;j++)
        {
            temp.push_back(j);
            getRes(res,temp,k,j+1,n);
            temp.pop_back();
        }
    }
};