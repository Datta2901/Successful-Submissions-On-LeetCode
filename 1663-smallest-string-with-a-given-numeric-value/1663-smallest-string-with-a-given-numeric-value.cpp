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
            // if(k - i >= 0 && (k - i) + answer.size() + 1 == n ){
            //     answer += 'a' + i - 1;
            //     cerr << answer[answer.size() - 1] << " " << i - 1 << endl;
            //     k -= i;
            // }else{
                i--;
            // }
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};