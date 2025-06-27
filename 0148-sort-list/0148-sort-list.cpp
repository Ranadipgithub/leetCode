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
private:
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *res;
        if(list1->val < list2->val){
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        } else{
            res = list2;
            res->next = mergeTwoLists(list1, list2->next);
        }
        return res;
    }

public:
    ListNode* sortList(ListNode* head) {
        // ListNode *temp = head;
        // vector<int> arr;
        // if(head == nullptr || head->next == nullptr){
        //     return head;
        // }
        // while(temp){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(arr.begin(), arr.end());
        // temp = head;
        // int i = 0;
        // while(temp){
        //     temp->val = arr[i];
        //     i++;
        //     temp = temp->next;
        // }
        // return head;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode *result = mergeTwoLists(left, right);
        return result;
    }
};