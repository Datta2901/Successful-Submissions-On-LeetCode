class Solution {
public:
   bool isPalindrome(string s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void getAnswer(int i,vector<vector<string>>&answer,vector<string>ds,string s){
        if(i == s.size()){
            answer.push_back(ds);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s,i,j)){
                ds.push_back(s.substr(i,j - i + 1));
                getAnswer(j + 1,answer,ds,s);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<vector<string> > answer;
        vector<string>ds;
        getAnswer(0,answer,ds,s);
        return answer;
    }
};