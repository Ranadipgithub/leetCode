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
    ListNode* swapPairs(ListNode* head) {
        vector<int> res;
        ListNode *temp = head;
        while(temp){
            res.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 1;i<res.size();i+=2){
            swap(res[i], res[i-1]);
        }
        temp = head;
        int i = 0;
        while(temp){
            temp->val = res[i++];
            temp = temp->next;
        }
        return head;
    }
};