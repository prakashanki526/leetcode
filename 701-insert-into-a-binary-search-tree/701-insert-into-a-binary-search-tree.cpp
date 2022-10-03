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
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* node = root;
        while(true){
            if(node->val<val){
                if(node->right==NULL){
                    node->right = new TreeNode(val);
                    return root;
                }
                node = node->right;
            }
            else{
                if(node->left==NULL){
                    node->left = new TreeNode(val);
                    return root;
                }
                node = node->left;
            }
        }
    }
};