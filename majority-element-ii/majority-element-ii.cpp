class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MAX,ele2 = INT_MAX;
        int count1 = 0,count2 = 0;
        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){
               count1++; 
            }else if(ele2 == nums[i]){
                count2++;
            }else if(count1 == 0){
                ele1 = nums[i];
                count1++;
            }else if(count2 == 0){
                ele2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        vector<int>answer;
        if(count1 == 0 && count2 == 0){
            return {};
        }
        count1 = 0,count2  = 0;
        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){
                count1++;
            }else if(ele2 == nums[i]){
                count2++;
            }
        }
        if(count1 > n / 3){
            answer.push_back(ele1);
        }if(count2 > n / 3){
            answer.push_back(ele2);
        }
        return answer;
    }
};