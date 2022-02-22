class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int num = 0,count = 0;
        long  power = 1;
        for(int i = n - 1; i >= 0; i--){
            // int power = pow(26,count);
            num += (power * ((columnTitle[i] - 'A') + 1));
            power *= 26;
            count++;
            // cout << num << " ";
        }
        return num;
    }
};