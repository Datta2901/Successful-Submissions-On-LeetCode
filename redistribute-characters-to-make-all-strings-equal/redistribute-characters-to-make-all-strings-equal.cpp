class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> freq;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                freq[words[i][j]]++;
            }
        }

        for(auto it : freq){
            if((it.second) % words.size() != 0){
                return false;
            }
        }
        return true;
    }
};