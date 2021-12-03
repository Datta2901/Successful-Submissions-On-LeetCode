class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int minProduct = nums[0],maxProduct = nums[0];
        int answer = nums[0];
        for(int i = 1; i < n; i++){
            int curr = nums[i];
            if(nums[i] < 0){
                swap(minProduct,maxProduct);
            }
            maxProduct = max({maxProduct * curr,curr});
            minProduct = min({minProduct * curr,curr});
            answer = max(maxProduct,answer);
        }
        return answer;
    }
};
