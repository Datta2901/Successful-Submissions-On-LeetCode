class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>fre;
        for(auto it : s){
            fre[it]++;
        }
        for(auto it : t){
            fre[it]--;
        }
        for(auto it : fre){
            // cout << it.first << " " << it.second << endl;
            if(it.second < 0){
                return it.first;
            }
        }
        return 'a';
    }
};