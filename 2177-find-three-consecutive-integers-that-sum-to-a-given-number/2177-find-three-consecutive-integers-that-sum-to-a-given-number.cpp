class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>answer;
        if(num % 3 != 0){
            return answer;
        }
        long long x = num / 3;
        if(3 * x == num){
            answer.push_back(x - 1);
            answer.push_back(x);
            answer.push_back(x + 1);
        }
        return answer;
    }
};