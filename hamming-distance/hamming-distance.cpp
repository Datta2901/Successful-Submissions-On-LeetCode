class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xbits(x), ybits(y);
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans += xbits[i] != ybits[i];
        }
        return ans;
    }
};