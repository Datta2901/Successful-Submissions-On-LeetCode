class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = 1,maxProduct = 1;
        int answer = INT_MIN;
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            int temp = maxProduct * curr;
            maxProduct = max({minProduct * curr,maxProduct * curr,curr});
            minProduct = min({minProduct * curr,temp,curr});
            answer = max(maxProduct,answer);
        }
        return answer;
    }
};
