class Solution {
public:
    int arrangeCoins(int n) {
        int ans = int(sqrt(2 * (long int)n + 0.25) - 0.5);
        return ans;
    }
};