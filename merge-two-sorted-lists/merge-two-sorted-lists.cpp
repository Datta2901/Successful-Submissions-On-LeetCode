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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *answer = NULL,*temp;
    while(l1 || l2){
        if(answer == NULL){
            if(l1->val < l2->val){
                ListNode* newListnode = new ListNode();
                newListnode->val = l1->val;
                answer = newListnode;
                temp = answer;
                l1 = l1->next;
            }else if(l1->val >= l2->val){
                ListNode* newListnode = new ListNode();
                newListnode->val = l2->val;
                answer = newListnode;
                temp = answer;
                l2 = l2->next;
            }
        }
        if(l1 && l2){
            if(l1->val < l2->val){
                ListNode* newListnode = new ListNode();
                newListnode->val = l1->val;
                l1 = l1->next;
                temp->next = newListnode;
                temp = newListnode;
            }else{
                ListNode* newListnode = new ListNode();
                newListnode->val = l2->val;
                l2 = l2->next;
                temp->next = newListnode;
                temp = newListnode;
            }
        }else if(l1){
            while(l1 != NULL){
                ListNode* newListnode = new ListNode();
                newListnode->val = l1->val;
                l1 = l1->next;
                temp->next = newListnode;
                temp = newListnode;
            }
        }else if(l2){
            while(l2 != NULL){
                ListNode* newListnode = new ListNode();
                newListnode->val = l2->val;
                l2 = l2->next;
                temp->next = newListnode;
                temp = newListnode;
            }
        }
    }
    
    temp->next = NULL;
    return answer;
    }
};