// class Solution {
// public:
//     int countOdds(int low, int high) {
//         int count = 0;
//         for(int i = low; i <= high; i++){
//             if(i % 2 == 1){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countOdds(int low, int high) {
        int count = (high - low) / 2;
        if(high % 2 == 1 || low % 2 == 1){
            count++;
        }
        return count;
    }
};