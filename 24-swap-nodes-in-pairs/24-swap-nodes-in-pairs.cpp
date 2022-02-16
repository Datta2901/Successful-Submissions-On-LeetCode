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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        vector<int>ans;
        while(temp){
            ans.push_back(temp->val);
            int size = ans.size();
            if(size % 2 == 0){
                swap(ans[size - 1],ans[size - 2]);
            }
            temp = temp->next;
        }
        temp = head;
        int index = 0;
        while(temp){
            temp->val = ans[index++];
            temp = temp->next;
        }
        return head;
    }
};