/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_set<ListNode*>s;
        while(temp!=NULL){
            if(s.find(temp)!=s.end())
                return 1;
            s.insert(temp);
            temp=temp->next;
        }
        return 0;
    }
};