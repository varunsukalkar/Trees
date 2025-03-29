/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        r(root,0,res);
        return res;
    }

    void r(TreeNode * root , int level , vector<int> & res){
        if(root == nullptr){
            return ;
        }
        if(res.size() == level){
            res.push_back(root->val);
        }
        r(root->right  , level+1 ,res);
        r(root->left , level+1 , res);
    }

    


    
};