Unique Binary Search Trees II
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
    TreeNode * clone(TreeNode * node)
    {
        if(node==nullptr)
            return nullptr;
        TreeNode* p=new TreeNode(node->val);
        p->left=clone(node->left);
        p->right=clone(node->right);
        return p;
    }
    vector<TreeNode*> generateTrees(int n) {
        struct TreeNode * node;
        struct TreeNode *p,*q,*r;
        vector<TreeNode*> res;
        vector<TreeNode*> vec;
        if(n==0)
            return res;
        if(n==1)
        {
            node=new TreeNode(n);
            res.push_back(node);
            return res;
        }
               
        else
        {
            res=generateTrees(n-1);
            for(vector<TreeNode*>::iterator it=res.begin();it!=res.end();it++)
            {
                r=p=clone(*it);
                node=new TreeNode(n);
                node->left=p;
                vec.push_back(clone(node));
                while(p->right)
                {
                    q=p->right;
                    node=new TreeNode(n);
                    p->right=node;
                    node->left=q;
                    vec.push_back(clone(r));
                    p->right=q;
                   // delete()
                    p=p->right;
                }
                node=new TreeNode(n);
                p->right=node;
                vec.push_back(clone(r));
                
            }
            return vec;
        }
               
    }
};