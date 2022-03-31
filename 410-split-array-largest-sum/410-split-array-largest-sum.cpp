class Solution {
public:
    int memo[1001][51];
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++) {
            for (int currIndex = 0; currIndex < n; currIndex++) {
                if (subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
};