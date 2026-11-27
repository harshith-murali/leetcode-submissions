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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the 2nd half of the ll
        ListNode* mid = slow;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(mid){
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }

        int res = 0;
        ListNode* ptr = head;
        while (prev) {
            int val = ptr->val + prev->val;
            res = max(val, res);
            ptr = ptr->next;
            prev = prev->next;
        }

        return res;

    }
};