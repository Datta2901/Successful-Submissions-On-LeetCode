class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] % 2 == 0){
                if(i != odd){
                    swap(nums[i],nums[odd]);
                }
                odd++;
            }
        }
        return nums;
    }
};