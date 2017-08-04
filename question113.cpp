/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>path;
        vector<vector<int>>res;
        if(!root)
            return res;
        path.push_back(root->val);
        DFS(root,sum,path,res);
        return res;
    }
    void DFS(TreeNode* root,int sum,vector<int> &path,vector<vector<int>> &res){
        
        if(!root)
            return;
      //  cout<<root->val<<' '<<sum<<endl;
        if(!root->left&&!root->right){
            if(sum==root->val)
            {   res.push_back(path);
//                 for(vector<int>::iterator it=path.begin();it!=path.end();it++)
                    
                 
//                 cout<<*it;
            }
               
            return;
        }
        if(root->left)
        {
            path.push_back(root->left->val);
            DFS(root->left,sum-root->val,path,res);
            path.pop_back();
        }
        if(root->right)
        {
            path.push_back(root->right->val);
            DFS(root->right,sum-root->val,path,res);
            path.pop_back();
        }     
    }
        
};