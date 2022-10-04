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
    bool solve(TreeNode* root, int target, int sum){
        if(!root->left && !root->right){
            if(sum+root->val == target)
                return 1;
            return 0;
        }
        bool l = 0;
        if(root->left)
            l = solve(root->left,target,sum+root->val);
        bool r = 0;
        if(root->right)
            r = solve(root->right,target,sum+root->val);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        return solve(root,targetSum,0);
    }
};