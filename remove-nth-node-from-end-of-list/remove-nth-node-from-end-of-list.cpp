class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }if(head->next == NULL){
            return NULL;
        }
        ListNode *temp = head,*prev = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        }
        temp = head;
        int count = 0;
        while(temp){
            if(size - n == 0){
                ListNode* node = head;
                head = head->next;
                delete(node);
                return head;
            }
            if(count == size - n){
                ListNode* node = temp;
                prev->next = (temp->next);
                delete(node);
                return head;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};