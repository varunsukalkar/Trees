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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxi = maxDepth(root); 
        return dfs(root, maxi, 0);
    }

    TreeNode* dfs(TreeNode* root, int maxi, int len) {
        if (!root) return nullptr;  
        if (maxi - 1 == len) return root;
        TreeNode* left = dfs(root->left, maxi, len + 1);
        TreeNode* right = dfs(root->right, maxi, len + 1);
        
        if (left && right) return root;
        return left ? left : right;
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};