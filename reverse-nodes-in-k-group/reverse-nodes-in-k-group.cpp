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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>answer;
        ListNode* temp = head;
        int index = 0;
        while(temp){
            answer.push_back(temp->val);
            if(answer.size() % k == 0){
                reverse(answer.begin() + index,answer.end());
                index = answer.size();
            }
            temp = temp->next;
        }
        temp = head;
        index = 0;
        while(temp){
            temp->val = answer[index++]; 
            temp = temp->next;
        }
        return head;
    }
};