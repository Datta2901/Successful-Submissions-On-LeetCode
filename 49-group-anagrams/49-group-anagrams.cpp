class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > answer(strs.size());
        vector<pair<string,int> > fre;
        string a = "";
        for(int i = 0; i < strs.size(); i++){
            a = strs[i];
            sort(a.begin(),a.end());
            fre.push_back({a,i});
        }
        sort(fre.begin(),fre.end());
        for(auto it : fre){
            cout << it.first << " " << it.second << endl;
        }
        string start = fre[0].first;
        int sIndex = fre[0].second;
        int index = 0;
        vector<string>temp;
        for(int i = 1; i < fre.size(); i++){
            if(start == fre[i].first){
                cout << strs[fre[i].second] << " ";
                answer[index].push_back(strs[fre[i].second]);
            }else{
                answer[index].push_back(strs[sIndex]);
                index++;
                start = fre[i].first;
                sIndex = fre[i].second;
            }
        }
        answer[index].push_back(strs[sIndex]);
        int i = 0;
       while(i < answer.size()){
            if(answer[i].size() == 0){
                answer.erase(answer.begin() + i);
            }else{
                i++;
            }
        }
        return answer;
    }
};