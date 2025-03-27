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
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty()){
        root= q1.top();
       
        q1.pop();
        q2.push(root);
        if(root->left != NULL){
            q1.push(root->left);
        }
        if(root->right !=  NULL){
            q1.push(root->right);
        }



        }
        while(!q2.empty()){
            ans.push_back(q2.top()->val);
            q2.pop();
        }
          return ans;
    }
};