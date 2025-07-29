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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> arr;
        for(int i = 0;i<n;i++){
            ListNode *head = lists[i];
            ListNode *temp= head;
            while(temp){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        int m = arr.size();
        sort(arr.begin(), arr.end());
        ListNode *dummy = new ListNode(1);
        ListNode *temp = dummy;
        for(int i = 0;i<m;i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};