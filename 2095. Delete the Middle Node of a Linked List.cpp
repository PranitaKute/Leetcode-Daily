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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* firstPointer = head;
        ListNode* secondPointer = head;
        ListNode* previous = NULL;
        while(firstPointer && firstPointer->next){
            previous = secondPointer;
            secondPointer = secondPointer->next;
            firstPointer = firstPointer->next->next;
            // when first reaches the end, second is half way
        }
        if(previous){
            previous->next = secondPointer->next;
            // remove middle
            delete secondPointer;   // memory 
        }

        return head;
    }
};
