class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            auto it = words[i].find(pref);
            if(it == 0){
                count++;
            }
        }
       return count; 
    }
};