class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int answer = 0;
        unordered_map<int,int>mpp;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(sum == 0){
                answer = max(answer, i + 1);
            }
            if(mpp[sum] != 0){
                answer = max(answer,(i - mpp[sum]) + 1);
            }else{
                mpp[sum] = i + 1;
            }
        }
        return answer;
    }
};