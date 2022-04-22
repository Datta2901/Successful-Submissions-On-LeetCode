class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto maxi = max_element(arr.begin(),arr.end());
        return maxi-arr.begin();
    }
};