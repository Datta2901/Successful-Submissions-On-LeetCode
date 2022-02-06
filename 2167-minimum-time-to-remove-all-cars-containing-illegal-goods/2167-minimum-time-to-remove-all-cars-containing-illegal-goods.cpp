class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(),left = 0;
        int answer = INT_MAX;
        for(int i = 0; i < n; i++){
            left = min(left + (s[i] - '0') * 2, i + 1);
            answer = min(answer,left + n - i - 1);
        }
        return answer;
    }
};