/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

    TreeNode *build(ListNode *head)
    {
        // If the list is empty then return null
        if (!head)
            return NULL;

        // If the list contains only one element then return TreeNode of that value
        if (middleNode(head) == head)
            return new TreeNode(head->val);

        // Finding the middle node
        ListNode *middle = middleNode(head);

        // Making middle node as root
        TreeNode *root = new TreeNode(middle->val);

        // Dividing list into to parts
        // 1. Left part will have elements which is left to 'middle' node
        // 2. Right part will have elements which is right to 'middle' node
        ListNode *ptr = head;
        while (ptr->next != middle)
            ptr = ptr->next;

        ListNode *first = head;
        ListNode *second = middle->next;

        // Removing middle from the list
        ptr->next = NULL;
        middle->next = NULL;

        // building BST recursively
        root->left = build(first);
        root->right = build(second);

        // returning root
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        return build(head);
    }
};