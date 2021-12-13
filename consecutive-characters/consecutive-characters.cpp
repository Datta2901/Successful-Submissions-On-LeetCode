class Solution {
public:
    int maxPower(string s) {
        int answer = 1;
        int n = s.size();
        int count = 1;
        char a = s[0];
        for(int i = 1; i < n; i++){
            if(a == s[i]){
                count++;
                answer = max(answer,count);
            }else{
                count = 1;
                a = s[i];
            }
        }
        return answer;
    }
};