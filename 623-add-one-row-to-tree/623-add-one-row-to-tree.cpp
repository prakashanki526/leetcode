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
    void solve(vector<TreeNode*>v, int val){
        for(int i=0;i<v.size();i++){
            TreeNode*left = new TreeNode(val);
            TreeNode*right = new TreeNode(val);
            left->left = v[i]->left;
            right->right = v[i]->right;
            v[i]->left = left;
            v[i]->right = right;
        }
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL)
            return new TreeNode(val);
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>v;
        for(int i=0;i<depth-1;i++){
            int n = q.size();
            for(int j=0;j<n;j++){
                TreeNode* temp = q.front();
            q.pop();
                if(i==depth-2)
                    v.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        solve(v,val);
        return root;
    }
};