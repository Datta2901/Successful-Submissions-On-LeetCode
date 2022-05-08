// O(n3)
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int size = nums.size();
//         for(int i = 0; i < size; i++){
//             for(int j = i + 1 ; j < size; j++){
//                 for(int k = j + 1; k < size; k++){
//                     if(nums[i] < nums[k] && nums[k] < nums[j]){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

// O(n2)
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int size = nums.size();
//         int mini = nums[0];
//         for(int i = 0; i < size; i++){
//             for(int j = i + 1 ; j < size; j++){
//                 if(mini < nums[j]  && nums[j] < nums[i]){
//                     return true;
//                 }
//                 mini = min(mini,nums[i]);
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        int mini = nums[0];
        int third = INT_MIN;
        stack<int>store;
        for(int i = size - 1; i >= 0; i--){
            if(nums[i] < third){
                return true;
            }
            while(!store.empty() && nums[i] > store.top()){
                third = store.top();
                store.pop();
            }
            store.push(nums[i]);
        }
        return false;
    }
};
