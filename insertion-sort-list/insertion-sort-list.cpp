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
    ListNode* insertionSortList(ListNode* head) {
            if( head == NULL ){
                return head;
            }

            ListNode* dummy = new ListNode(0); 
            ListNode* current = head; 
            ListNode* previous = dummy; 
            ListNode* next = NULL; 
            while( current != NULL ){
                next = current->next;
                while( previous->next != NULL && previous->next->val < current->val ){
                    previous = previous->next;
                }
                current->next = previous->next;
                previous->next = current;
                previous = dummy;
                current = next;
            }

            return dummy->next;
        }
};