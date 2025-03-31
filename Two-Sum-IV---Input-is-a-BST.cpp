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


 class bst{
public :
stack<TreeNode * >mystack;
bool reverse = true;

bst(TreeNode * root , bool isreverse){
    reverse = isreverse;
    pushall(root);
}
bool hasnext(){
    return !mystack.empty();

}
int next(){
    TreeNode * tmpnode  = mystack.top();
    mystack.pop();
    if(!reverse)pushall(tmpnode->right);
    else pushall(tmpnode->left);
    return tmpnode->val;
}
void pushall(TreeNode * node){
    for(; node != nullptr;){
        mystack.push(node);
        if(reverse==true){
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
}
 };
class Solution {
public:
   
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        bst l(root,false);
        bst r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k )return true;
            else if(i+j < k )i = l.next();
            else j= r.next();
        }
        return false;

    }
};