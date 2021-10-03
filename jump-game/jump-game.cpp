class Solution{
    public:
        bool canJump(vector<int>& nums) {
            int size = nums.size() - 1;
            if(size == 0){
                return true;
            }
            int answer = 0;
            for(int i = 0; i < size; i++){
                answer = max(answer, i + nums[i]);
                if(answer == i){
                    return false;
                }
            }
            return true;
        }
};