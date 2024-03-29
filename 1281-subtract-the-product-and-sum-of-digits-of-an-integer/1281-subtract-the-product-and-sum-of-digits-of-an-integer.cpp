class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int digi;
        while(n > 0){
            digi = n % 10;
            product *= digi;
            sum += digi;
            n = n / 10;
        }
        return product - sum;
    }
};