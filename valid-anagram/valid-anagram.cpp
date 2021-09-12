class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int>mag(26,0);
        for(int i = 0; i < s.size(); i++){
            mag[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            if(mag[t[i] - 'a'] > 0){
                mag[t[i] - 'a'] -= 1;
            }else{
                return false;
            }
        }
        return true;
    }
};