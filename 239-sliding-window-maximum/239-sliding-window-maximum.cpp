class Solution {
private:
    vector<int> getAnswer(vector<int>&nums,int k){
        int size = nums.size();
        int i = 0,j = 0;
        list<int>maxi;
        vector<int>answer;
        while(j < size){
            if(maxi.size() == 0){
                maxi.push_back(nums[j]);
            }else{
                while(!maxi.empty() && nums[j] > maxi.back()){
                    maxi.pop_back();
                }
                maxi.push_back(nums[j]);
            }

            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                if(maxi.size() == 0){
                    answer.push_back(0);
                }else{
                    answer.push_back(maxi.front());
                    if(maxi.front() == nums[i]){
                        maxi.pop_front();
                    }
                }
                i++;
                j++;
            }
        }
        return answer;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return getAnswer(nums,k);
    }
};