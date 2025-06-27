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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *prev = nullptr;
        int cnt = 0;

        while (curr) {
            cnt++;
            curr = curr->next;
        }
        if (n == cnt) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        curr = head;
        for (int i = 0; i < cnt - n; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (prev && curr) {
            prev->next = curr->next;
            delete curr;
        }
        return head;
    }
};
