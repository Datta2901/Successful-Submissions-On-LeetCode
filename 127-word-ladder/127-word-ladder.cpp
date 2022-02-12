class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> fre;
        for(auto it : wordList){
            fre[it] = true;
        }
        if(fre[endWord] == false){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int answer = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string f = q.front();
                q.pop();
                for(int i = 0; i < f.size(); i++){
                    string oneChange = f;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        oneChange[i] = ch;
                        if(oneChange == f){
                            continue;
                        }if(oneChange == endWord){
                            return answer + 1;
                        }if(fre[oneChange] == true){
                            q.push(oneChange);
                            fre[oneChange] = false;
                        }
                    }
                }
            }  
            answer++;
        }
        return 0;
    }
};