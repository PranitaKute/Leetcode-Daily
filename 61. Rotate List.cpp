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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        int cnt_node  = 1;
        ListNode *curr = head;
        while(curr->next){
            curr = curr->next;
            cnt_node++;
        }
        k %= cnt_node;
        if(k == 0){
            return head;
        }
        curr->next = head;
        int second_half_count = cnt_node - k;
        while(second_half_count--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
