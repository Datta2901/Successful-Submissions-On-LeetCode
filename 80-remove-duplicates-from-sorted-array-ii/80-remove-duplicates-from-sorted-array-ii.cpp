// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>answer;
//         int count = 1;
//         answer.push_back(nums[0]);
//         for(int i = 1; i < n; i++){
//             if(nums[i] == nums[i - 1]){
//                 count++;
//                 if(count < 3){
//                     answer.push_back(nums[i]);
//                 }
//             }else{
//                 count = 1;
//                 answer.push_back(nums[i]);
//             }
//         }
//         nums = answer;
//         return answer.size();
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto it : nums){
            if(i < 2 || it > nums[i - 2]){
                nums[i++] = it;
            }
                
        }
        return i;
    }
};