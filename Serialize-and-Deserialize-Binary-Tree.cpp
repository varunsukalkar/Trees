/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = \\;
        if(root == nullptr){
            return str ;
        }
        queue<TreeNode * >q;
        q.push(root);
        while(!q.empty()){
            TreeNode * current = q.front();
            q.pop();
            if(current==nullptr){
                str.append(\#,\);
            }
            else{
                str.append(to_string(current->val)+',');
                if(current!=nullptr){
                   q.push(current->left);
                   q.push(current->right);
                }
            }

        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }


        stringstream s(data);
        string str ;
        getline(s,str,',');
        TreeNode * root = new TreeNode(stoi(str));
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            getline(s,str,',');
            if(str==\#\){
                node->left=nullptr;
            }
            else{
                TreeNode * leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str==\#\){
                node->right = nullptr;
            }else{
                TreeNode * rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));