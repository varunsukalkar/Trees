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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode * , TreeNode * > parent_mark;
        queue<TreeNode * > q;
        q.push(root);
        TreeNode * target = nullptr;
        while(!q.empty()){
            TreeNode * current = q.front();
            q.pop();
            if(current ->val == start){
               target = current;
            }
            if(current->left ){
                parent_mark[current->left]= current;
                q.push(current->left);
            }
            if(current->right){
                parent_mark[current->right]= current;
                q.push(current->right);
            }

        }

        unordered_map<TreeNode * , bool>visited;
        queue<TreeNode *> queue;
        queue.push(target);
       visited[target]= true;
        int count =0;
       
        while(!queue.empty()){
              int fl = 0 ;
               int size = queue.size();
        for(int i = 0; i< size; i++){
            TreeNode * current = queue.front();
            queue.pop();
            if(current->left && !visited[current->left]){
               fl = 1   ;
               queue.push(current->left);
               visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                fl = 1;
                queue.push(current->right);
                visited[current->right]= true;
            }
            if(parent_mark[current] && !visited[parent_mark[current]]){
                fl = 1;
                queue.push(parent_mark[current]);
                visited[parent_mark[current]]=true;
            }
        

        }
         if(fl)count++;
        }
    
return count;

    }
};