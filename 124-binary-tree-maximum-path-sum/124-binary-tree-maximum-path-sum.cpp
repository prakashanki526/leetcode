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
    int sum = INT_MIN;
    int solve(TreeNode* node){
        if(node==NULL)
            return 0;
        int ls = max(0,solve(node->left));
        int rs = max(0,solve(node->right));
        int cs = ls+rs+node->val;
        sum = max(sum,cs);
        return max(ls,rs)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};