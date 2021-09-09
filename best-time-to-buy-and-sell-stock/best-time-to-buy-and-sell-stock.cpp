class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxRight = INT_MIN,profit = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            maxRight = max(maxRight,prices[i]);
            profit = max(profit,maxRight - prices[i]);
        }
        return profit;
    }
};