class Solution {
    int getOneCount(int n){
        int count = 0;
        while(n){
            if(n & 1){
                count += 1;
            }
            n = n >> 1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int>answer;
        for(int i = 0; i <= n; i++){
            // answer.push_back(__builtin_popcount(i));
            answer.push_back(getOneCount(i));
        }
        return answer;
    }
};