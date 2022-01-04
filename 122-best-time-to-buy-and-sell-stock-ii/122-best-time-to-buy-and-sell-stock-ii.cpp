class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int answer = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i - 1]){
                answer += prices[i] - prices[i - 1];
            }
        }
        return answer;
    }
};