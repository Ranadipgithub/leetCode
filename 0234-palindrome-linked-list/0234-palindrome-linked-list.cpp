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
    bool isPal(vector<int>&arr){
        int n = arr.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        vector<int> res;
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        if(isPal(res)){
            return true;
        }
        return false;
    }
};