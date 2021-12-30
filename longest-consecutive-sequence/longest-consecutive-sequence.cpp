// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n =nums.size();
//         int answer = 1;
//         int count;
//         if(n == 0){
//             return 0;
//         }if(n == 1){
//             return 1;
//         }
//         set<int>fre;
//         for(int i = 0; i < n; i++){
//             fre.insert(nums[i]);
//         }
//         for(int i = 0; i < n; i++){
//             if(fre.count(nums[i] - 1) == 0){
//                 count = 1;
//                 int current = nums[i];
//                 while(fre.count((current + 1))){
//                     current++;
//                     count++;
//                 }
//                 answer = max(answer,count);
//             }
//         }
//         return answer;
//     }
// };


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        int answer = 1;
        int count;
        if(n == 0){
            return 0;
        }
        map<int,int> fre;
        for(int i = 0; i < n; i++){
            fre[nums[i]] = 1;
        }
        for(int i = 0; i < n; i++){
            if(fre[nums[i] - 1] == 0){
                count = 1;
                //including nums[i] - 1,nums[i]
                int current = nums[i];
                while(fre[current + 1] != 0){
                    current++;
                    count++;
                }
                answer = max(answer,count);
            }
        }
        return answer;
    }
};