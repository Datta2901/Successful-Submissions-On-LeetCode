class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer = "";
        for(int i = n; i > 0; i--){     
            int remaining = k - (i - 1);       
            if(remaining >= 26){
                answer += 'z';
                k -= 26;
            }else{
                answer += 'a' + remaining - 1;
                k -= remaining;
            }
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
