// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         while(n){
//             if(n & 1){
//                 count += (n & 1);
//             }
//             n = n >> 1;
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         while(n){
//             if(n % 2 == 1){
//                 count += 1;
//             }
//             n = n / 2;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};