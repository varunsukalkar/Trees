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
   
        void find(TreeNode * root , vector<string> & str,string temp ){
            if(root) temp +=to_string(root->val);
            if(root->left) find(root->left , str,temp+\->\);
            if(root->right)find(root->right ,str,temp+\->\);
            if(!root->left && !root->right ){
                str.push_back(temp);
            }
        }

    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
       find(root , ans,\\);
       return ans;
    
    }
};