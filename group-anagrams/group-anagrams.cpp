class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> fre;
        vector<vector<string> > a(strs.size());
        int index = 1;
        for(int i = 0; i < strs.size(); i++){
            string s  = strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(fre[strs[i]] == 0){
                fre[strs[i]] = index++;
            }
            a[fre[strs[i]] - 1].push_back(s);
        }
        for (int i = 0; i < a.size(); ) {
            if (a[i].size() == 0) {
                a.erase(a.begin() + i);
            } else{
                ++i;
            }
        }
        return a;
    }
};