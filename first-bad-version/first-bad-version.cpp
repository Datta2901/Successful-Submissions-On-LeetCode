// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        for(int i = n -1; i >= 0; i--){
            // cout << isBadVersion(i) << endl;
            if(!isBadVersion(i)){
                return i + 1;
            }
        }
        return 0;
    }
};