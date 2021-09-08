class Solution {
public:
    char shiftChar(char a,long long int  k){
        char ans = 'a';
        k = k % 26;
        if(a + k > 'z'){
            int diff = 'z' - a;
            k -= diff;
            ans = ans + k - 1;
        }else{
            ans = a + k;
        }
        return ans;
    }
    

    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long int>suffixSum(n,0);
        long long int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += shifts[i];
            suffixSum[i] = sum;
        }
        string answer = "";
        for(int i = 0; i < n; i++){
            answer +=( shiftChar(s[i],suffixSum[i]));
        }
        return answer;
    }
};