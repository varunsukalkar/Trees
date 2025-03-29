/**
 * Definition for a binary tree Treenode.
 * struct TreeTreenode {
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int,map<int,multiset<int>>>nodes;
      queue<pair<TreeNode * , pair<int ,int>>>queue;
      queue.push({root,{0,0}});
      while(!queue.empty()){
        auto w = queue.front();
        queue.pop();
        TreeNode * t = w.first;
        int x = w.second.first;
        int y = w.second.second;
        nodes[x][y].insert(t->val);
        if(t->left){
            queue.push({t->left,{x-1,y+1}});
            
        }
        if(t->right){
            queue.push({t->right,{x+1,y+1}});
        }



      }
      vector<vector<int>>ans;
      for(auto it :nodes){
        vector<int>val;
        for(auto q :it.second){
                    val.insert(val.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(val);
      }
             return ans;
    }
};