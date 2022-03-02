class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        int n = s.size();
        int m = t.size();
        while(i < n && j < m){
            while(j < m && s[i] != t[j]){
                j++;
            }
            if(j < m && s[i] == t[j]){
                i++;
                j++;
            }
        }
        if(i == n){
            return true;
        }
        return false;
    }
};