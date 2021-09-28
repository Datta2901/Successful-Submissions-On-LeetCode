class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer(n);
        int EvenPos = 0,OddPos = 1;
        for(int i = 0; i < n; i++){
            if(EvenPos < n && nums[i] % 2 == 0){
                answer[EvenPos] = nums[i];
                EvenPos += 2;
            }
            if(OddPos < n && nums[i] % 2 == 1){
                answer[OddPos] = nums[i];
                OddPos += 2; 
            }
        }
        return answer;
    }
};