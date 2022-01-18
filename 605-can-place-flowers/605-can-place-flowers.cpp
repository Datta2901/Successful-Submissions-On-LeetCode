class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int zeros = 1, answer = 0;
        int n = flowerbed.size();
        for (int i = 0; i < n; i++) {
            if (flowerbed[i] == 0) {
                zeros++;
            }else{
                answer += (zeros - 1) / 2;
                zeros = 0;
            }
        }
        return answer + zeros / 2 >= k; 
    }
};