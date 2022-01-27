// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int ans = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 ans = max(ans,nums[i] ^ nums[j]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maximum = 0;
        int n = nums.size();
        
        int MaxPowerOf2 = 0;
        set<int>answer;
        
        for(int bits = 30; bits >= 0; bits--){
            
            MaxPowerOf2 = MaxPowerOf2 | (1 << bits);
            
            for(int i = 0; i < n; i++){
                answer.insert((MaxPowerOf2 & nums[i]));
            }
            
            int newMax = maximum | (1 << bits);
            
            for(auto it : answer){
                if(answer.count(newMax ^ it)){
                    maximum = newMax;
                    break;
                }        
            }
            
            answer.clear();
        }
        return maximum;
    }
};