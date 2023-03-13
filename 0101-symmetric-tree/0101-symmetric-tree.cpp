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
    bool solve(TreeNode* n1, TreeNode* n2){
        if(n1==NULL && n2==NULL)
            return 1;
        if(n1==NULL || n2==NULL)
            return 0;
        if(n1->val != n2->val)
            return 0;
        return solve(n1->left,n2->right)&&solve(n1->right,n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return 1;
        return solve(root->left,root->right);
    }
};