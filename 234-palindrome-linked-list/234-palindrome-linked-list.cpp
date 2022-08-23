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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *t=head;
        if(t==NULL)
            return true;
        string s;
        while(t!=NULL){
            s+=to_string(t->val);
            t=t->next;
        }
        string p=s;
        reverse(p.begin(),p.end());
        return p==s;
    }
};