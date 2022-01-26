// // Using fre
// class Solution {
// private:
//     map<int,int>fre;
// public:
    
//     int deleteAndEarn(vector<int>& nums) {
//         int maxi = INT_MIN;
//         int n = nums.size();
//         for(auto it : nums){
//             fre[it]++;
//             maxi = max(maxi,it);
//         }
//         // cout << maxi << endl;
        
//         vector<int>dp(maxi + 1,0);
        
//         dp[1] = fre[1];
//         if(n == 1){
//             return fre[nums[0]] * nums[0];
//         }
//         dp[2] = max(dp[1],fre[2] * 2);
//         for(int i = 3; i <= maxi; i++){
//             dp[i] = max(dp[i - 1],dp[i - 2] + fre[i] * (i));
//         }
        
//         return dp[maxi];
//     }
// };


// Using fre
class Solution {
private:
    int n = 10001;
public:
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int>sum(n,0),dp(n,0);
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            sum[num] += num;
        }
        dp[0] = 0;
        dp[1] = sum[1];
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
        }
        return dp[n - 1];
    }
};





