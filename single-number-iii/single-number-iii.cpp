class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int answer = 0;
        for(auto it : nums){
            answer ^= it;
        }
        unsigned int lastbit = answer & -(answer);
        int num1 = 0;
        for(auto it : nums){
            if((lastbit & it) != 0){
               num1  = num1 ^ it;
            }
        }
        return {(int)num1,int(num1 ^ answer)};
    }
};