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
    bool check(TreeNode* root, long long mini, long long maxi){
        if(root==NULL)
            return 1;
        if(root->val<=mini || root->val>=maxi)
            return 0;
        bool left = check(root->left,mini,(long long)root->val);
        bool right = check(root->right,(long long)root->val,maxi);
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,-1e18,1e18);
    }
};