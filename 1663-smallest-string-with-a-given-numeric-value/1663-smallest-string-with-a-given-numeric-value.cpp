class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer = "";
        int i  = 26;
        while(k > 0 && i >= 1){ 
            while(k - i >= 0){
                if((k - i) + answer.size() + 1 >= n){
                    answer += 'a' + i - 1;
                    k -= i;
                }else{
                    break;
                }
            }
            i--;
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};