class Solution {
public:
    bool isPerfectSquare(int num) {
        float a = float(sqrt(num));
        int b = sqrt(num);
        return a == b; 
    }
};