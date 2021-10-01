class MyLinkedList {
public:
    int val;
    ListNode *next,*head;

    MyLinkedList() {
        next = NULL;
        head = NULL;
    }
    
    int get(int index) {
        int count = 0;
        ListNode *temp = head;
        while(temp){
            if(count == index)
                return temp->val;
            temp = temp->next;
            count++;
        }
        return -1;
    }
    
  
    void addAtHead(int val) {
        ListNode *n = new ListNode;
        n->val = val;
        n->next = head;
        head = n;
    }
    void addAtTail(int val) {
        ListNode *n = new ListNode;
        n->val = val;
        if(!head)
            head = n;
        else{
            ListNode *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = n;
        }
    }
    
    void addAtIndex(int index, int val) {
        int len=0,count=0;
        ListNode *temp = head;
        ListNode* n = new ListNode;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(index>len)
            return;
        if(index==0){
            addAtHead(val);
            return;
        }
    
        temp = head;
        while(temp && count<index-1){
            temp = temp->next;
            count++;
        }
        n->val = val;
        ListNode *temp1 = temp->next;
        temp->next = n;
        n->next = temp1;
    }
    
    void deleteAtIndex(int index) {
        int len=0,count=0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(index == 0){
            if(head)
                head = head->next;
            return;
        }
        if(index>=len)
            return;
        temp = head;
        while(temp && count<index-1){
            temp=temp->next;
            count++;
        }
        temp->next = temp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */