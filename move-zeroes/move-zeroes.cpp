class Solution {
public:
   void moveZeroes(vector<int>& nums) {
        int pos = 0,i = 0,n = nums.size() - 1;
        while(i <= n){
            if(nums[i] != 0){
                nums[pos++] = nums[i];
            }
            i++;
        }

        int zeroes = n - pos;
        while(zeroes >= 0){
            nums[n--] = 0;
            zeroes--;
        }
    }
};