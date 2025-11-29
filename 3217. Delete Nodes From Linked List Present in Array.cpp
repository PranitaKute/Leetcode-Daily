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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>check;
        for(int num : nums){
            check.insert(num);
        }
        
        ListNode* dummy = new ListNode(0);      //if head is to be removed
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next != nullptr){
            if(check.count(curr->next->val)){
                ListNode* delNode = curr->next;
                curr->next = curr->next->next;
                // delete delNode;
            }
            else{
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
