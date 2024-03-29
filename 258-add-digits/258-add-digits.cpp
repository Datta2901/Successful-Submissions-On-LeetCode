class Solution {
private:
    int GetSum(int n){
        int s = 0;
        while(n > 0){
            s += (n % 10);
            n /= 10;
        }
        return s;
    }
public:
    int addDigits(int num) {
        int sum = num;
        while(!(0 <= sum && sum <= 9)){
            sum = GetSum(sum);
        }
        return sum;
    }
};