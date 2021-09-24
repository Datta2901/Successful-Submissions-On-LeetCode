class Solution {
public:
    int tribonacci(int n) {
        vector<int>answer(38,0);
        answer[0] = 0;
        answer[1] = 1;
        answer[2] = 1;
        for(int i = 3; i <= n; i++){
            answer[i] = answer[i - 1] + answer[i - 2] + answer[i - 3];
        }
        
        return answer[n];
    }
};