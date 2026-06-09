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
    ListNode* sortList(ListNode* head) {
        multiset<int> ms;
        ListNode* temp = head;
        while(temp!=NULL){
            ms.insert(temp->val);
            temp = temp ->next;
        }

        temp = head;
        for(auto it :ms ){
            temp ->val = it;
            temp =temp->next;
        }

        return head;
    }
};