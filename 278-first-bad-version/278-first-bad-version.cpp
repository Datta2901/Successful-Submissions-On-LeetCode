// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// class Solution {
// public:
//     int firstBadVersion(int n) {
//         for(int i = n -1; i >= 0; i--){
//             if(!isBadVersion(i)){
//                 return i + 1;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1,high = n;
        int answer = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(!isBadVersion(mid)){
                answer = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return answer + 1;
    }
};