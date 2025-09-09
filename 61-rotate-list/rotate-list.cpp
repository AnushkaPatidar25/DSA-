class Solution {
public:
    // Function to get length of list and return tail node also
    pair<ListNode*, int> getLength(ListNode* head) {
        ListNode* tail = nullptr;
        ListNode* ptr = head;
        int len = 0;
        while (ptr) {
            len++;
            tail = ptr;
            ptr = ptr->next;
        }
        return {tail, len};
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        auto [tail1, len] = getLength(head);
        k %= len;
        if (k == 0) return head;

        ListNode* ptr = head;
        ListNode* tail = nullptr;

        for (int i = 0; i < len - k; i++) {
            tail = ptr;
            ptr = ptr->next;
        }

        // Break and reconnect
        tail->next = nullptr;
        tail1->next = head;

        return ptr;
    }
};
    