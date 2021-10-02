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
    void reorderList(ListNode* head) {
        vector<int>answer;
        ListNode* temp = head;
        while(temp != NULL){
            answer.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int start = 0;
        bool s = true;
        int end = answer.size() - 1;
        bool e = false;
        while(temp != NULL){
            // cout << start << " " << end << endl;
                if(s){
                    temp->val = answer[start++];
                    s = false;
                }else{
                    temp->val = answer[end--];
                    s = true;
                }
            temp = temp->next;
        }
    }
};