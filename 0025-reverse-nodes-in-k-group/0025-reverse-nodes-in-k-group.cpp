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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> arr;
        ListNode *temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        for(int i = 0;i<n;i+=k){
            if(i+k <= n)
                reverse(arr.begin() + i, arr.begin()+i+k);
            // else reverse(arr.begin() + i, arr.end());
        }
        int i = 0;
        temp = head;
        while(temp){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};