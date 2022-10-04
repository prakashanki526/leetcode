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
    TreeNode* findpos(TreeNode* root){
        while(root->right!=NULL)
            root = root->right;
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        TreeNode* rightchild = root->right;
        TreeNode* postoinsert = findpos(root->left);
        postoinsert->right = rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val == key){
            root = helper(root);
            return root;
        }
        TreeNode* res = root;
        while(root!=NULL){
            if(root->left && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            if(root->right && root->right->val ==key){
                root->right = helper(root->right);
                break;
            }
            if(root->val<key)
                root = root->right;
            else
                root = root->left;
        }
        return res;
    }
};