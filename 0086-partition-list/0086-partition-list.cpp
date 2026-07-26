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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode(-1);
        ListNode* largeDummy = new ListNode(-1);

        ListNode* smallCurr = smallDummy;
        ListNode* largeCurr = largeDummy;
        ListNode* curr = head;

        while(curr){
            if(curr->val < x){
                smallCurr->next = curr;
                smallCurr = smallCurr->next;
            }else{
                largeCurr -> next = curr;
                largeCurr = largeCurr->next;
            }
            curr = curr -> next;
        }
        largeCurr->next = NULL;
        smallCurr->next = largeDummy->next;

        return smallDummy->next;
    }
};