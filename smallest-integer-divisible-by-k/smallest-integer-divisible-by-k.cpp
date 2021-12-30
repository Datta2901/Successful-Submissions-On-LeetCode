class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int answer = 0;
        int rem = 0;
        int num = 1;
        for(int i = 1; i <= k; i++){
            rem = ((rem * 10) + 1) % k;
            if(rem == 0){
                return i;
            }
        }
        return -1;
    }
};