class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, pos = 0, neg = 0;
        for (auto &it : nums) {
            if (it > 0) {
                pos = pos > 0 ? pos + 1 : 1;
                neg = neg > 0 ? neg + 1 : 0;
            }else if (it < 0) {
                int pp = pos, nn = neg;
                pos = nn > 0 ? nn + 1 : 0;
                neg = pp > 0 ? pp + 1 : 1;
            }else {
                pos = neg = 0;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};