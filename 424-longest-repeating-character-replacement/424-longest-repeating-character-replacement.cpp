class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>fre;
        int i = 0,j = 0;
        int answer = INT_MIN;
        int n = s.size();
        int maxFreq = 0;
        while(j < n){
            fre[s[j]]++;
            maxFreq = max(maxFreq,fre[s[j]]);
            // cout << << " "<< maxFreq << " ";
            int windowSize = j - i + 1;
            if(windowSize - maxFreq <= k){
                answer = max(answer,windowSize);
            }else{
                fre[s[i]]--;
                i++;
            }
            j++;
        }
        return answer;
    }
};