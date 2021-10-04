class Solution {
public:
    int minimumMoves(string s) {
        int count  = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'X'){
                i = i + 2;
                count++;
            }
            
        }
        return count;
    }
};
