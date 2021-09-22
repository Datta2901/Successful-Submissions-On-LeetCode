class Solution {
public:
    
    bool isUnique(string s){
        vector<bool>fre(26,false);
        for(int i = 0; i < s.size(); i++){
            // cout << s[i] - 'a' + 1 << " ";
            if(fre[s[i] - 'a' + 1]){
                return false;
            }else{
                fre[s[i] -'a' + 1] = true;
            }
        }
        return true;
    }
    
    int maxLength(vector<string>& arr) {
        string answer = "";
        vector<string>ans;
        ans.push_back("");
        int size = 0;
        for(int i = 0; i < arr.size(); i++){
            if(!isUnique(arr[i])){
                continue;
            }
            vector<string>temp;
            for(int j = 0; j < ans.size(); j++){
                string a = ans[j] + arr[i];
                if(isUnique(a)){
                    size = max(size, int(a.size()));
                    temp.push_back(a);
                }
            }
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return size;
    }
};