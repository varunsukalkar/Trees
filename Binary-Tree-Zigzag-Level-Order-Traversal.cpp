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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         
        vector<vector<int>>ans ;
        if(root== nullptr){
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        int lefttoright=true;
        while(!q.empty()){
            int size = q.size();
                        vector<int>vec(size);

            for(int i = 0 ; i< size; i++){
             TreeNode * current = q.front();
             q.pop();
             int index=0;
             if(lefttoright){
                index=i;
             }else{
                index = size-1-i;
             }
             vec[index] = current->val;
             if(current->left){
                q.push(current->left);
             }
             if(current->right){
                q.push(current->right);
             }
            }
            lefttoright =!lefttoright;
            ans.push_back(vec);
        }
        return ans;
    }
};