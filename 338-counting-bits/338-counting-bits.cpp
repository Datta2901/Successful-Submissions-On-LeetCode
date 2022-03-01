// TimeComplexity O(nlogn)
// class Solution {
//     int getOneCount(int n){
//         int count = 0;
//         while(n){
//             if(n & 1){
//                 count += 1;
//             }
//             n = n >> 1;
//         }
//         return count;
//     }
// public:
//     vector<int> countBits(int n) {
//         vector<int>answer;
//         for(int i = 0; i <= n; i++){
//             // answer.push_back(__builtin_popcount(i));
//             answer.push_back(getOneCount(i));
//         }
//         return answer;
//     }
// };

// TimeComplexity O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>answer(n + 1,0);
        if(n == 0){
            return answer;
        }
        answer[0] = 0;
        for(int i = 1; i <= n; i++){
            if(i % 2 == 0){
                answer[i] = answer[i / 2];
            }else{
                answer[i] = 1 + answer[i - 1];
            }
        }
        return answer;
    }
};