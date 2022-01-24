class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0;
        int capital = 0;
        bool start = false;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(isupper(word[i]) && i == 0){
                start = true;
            }
            if(isupper(word[i])){
                if(start){
                    capital++;
                }else{
                    return false;
                }
            }else{
                small++;
            }
        }
        if(small == n - 1 || small == n || capital == n){
            return true;
        }
        return false;
    }
};