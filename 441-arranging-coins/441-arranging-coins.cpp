// class Solution {
// public:
//     int arrangeCoins(int n) {
//         int ans = int(sqrt(2 * (long int)n + 0.25) - 0.5);
//         return ans;
//     }
// };

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0,high = n;
        while(low <= high){
            int mid = (low + high) / 2;
            long long sum = (long long)(mid) * (mid + 1) / 2;
         
            if(sum == n){
                return mid;
            }
            if(n > sum){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};