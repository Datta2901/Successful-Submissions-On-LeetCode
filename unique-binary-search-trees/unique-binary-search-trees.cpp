class Solution {
public:
    //catalan number 2nCn / (n + 1)    
    int numTrees(int n) {
        long answer = 1;
        for(int i = 0; i < n; i++){
            answer *= ((2 * n) - i);
            answer /= (i + 1);
        }
        return(answer / (n + 1));
    }
};