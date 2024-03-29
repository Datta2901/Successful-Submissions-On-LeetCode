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
    
public:
    int getDecimalValue(ListNode* head) {
        string num = "";
        while(head){
            num +=  to_string(head->val);
            head = head->next;
        }
        int answer = stoi(num,NULL,2);
        return answer;
    }
};