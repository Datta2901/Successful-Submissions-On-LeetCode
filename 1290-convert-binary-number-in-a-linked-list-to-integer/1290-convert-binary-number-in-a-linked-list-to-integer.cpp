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
    int to_binary(string num){
        int n = num.size();
        int ans = 0;
        int count = 0;
        for(int i = n - 1; i >= 0; i--){
           ans +=(num[i] - '0')* pow(2,count);   
           count++;
        }
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        string num = "";
        while(head){
            num +=  to_string(head->val);
            head = head->next;
        }
        // int answer = stoi(num,NULL,2);
        int answer = to_binary(num);
        return answer;
    }
};