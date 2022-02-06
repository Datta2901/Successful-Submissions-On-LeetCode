class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even,odd;
        if(nums.size() == 1){
            return nums;
        }
        int n = nums.size();
        for(int i = 0; i < n; i += 2){
            even.push_back(nums[i]);
            odd.push_back(nums[i + 1]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int i = 0;
        int e = 0,o = 0;
        while(e < even.size() || o < odd.size()){
            if(e < even.size()){
                nums[i] = even[e];
                i++;
                e++;
            }if(o < odd.size()){
                nums[i] = odd[o];
                o++;
                i++;
            }
        }
        return nums;
    }
};