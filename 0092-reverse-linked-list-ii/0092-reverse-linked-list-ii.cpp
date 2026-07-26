class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* beforeRange = dummy;

        // Reach the node before position `left`
        for (int i = 1; i < left; i++) {
            beforeRange = beforeRange->next;
        }

        ListNode* curr = beforeRange->next;
        ListNode* subListTail = curr;
        ListNode* prev = NULL;

        // Reverse nodes from left to right
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect the part before the range
        beforeRange->next = prev;

        // Connect the reversed range to the remaining list
        subListTail->next = curr;

        return dummy->next;
    }
};