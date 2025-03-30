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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        TreeNode * dummynode= root;
        while(true){
           
            if(val<root->val){
                if(root->left != nullptr ){
                root=root->left;
                }
                else{
                    TreeNode * newnode = new TreeNode(val);
                    root->left= newnode;
                    break;
                }
            }
            else{
               
                if(root->right!=nullptr){
                    root=root->right;
                }
                else{
                    TreeNode * newnode = new TreeNode(val);
                    root->right= newnode;
                    break;
                }
            }
        }
        return dummynode;
    }
};