class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> f1(26,0);
        
        for(int i = 0; i < m; i++){
            f1[s1[i] - 'a']++;
            // cout << f1[s1[i] - 'a'] << " ";
        }
        for(int i = 0; i < n; i++){
            vector<int>f2(26,0);
            for(int j = i; j < i + m; j++){
                if(j < n){
                    f2[s2[j] - 'a']++;
                }
            }
            if(f2 == f1){
                return true;
            }
        }
        return false;
    }
};