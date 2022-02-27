// class Solution {
// public:
    
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> goal(26), cur(26), res;
//         for(char c : p) goal[c - 'a']++;
//         for(int i = 0; i < s.size(); i++) {
//             cur[s[i] - 'a']++;
//             if(i >= p.size()) cur[s[i - p.size()] - 'a']--;
//             if(cur == goal) res.push_back(i - p.size() + 1);
//         }
//         return res;
//     }
// };

class Solution{
  public:
    vector<int> findAnagrams(string s,string p){
        vector<int>frep(26),freAnswer(26),answer;
        for(char ch : p){
            frep[ch - 'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            freAnswer[s[i] - 'a']++;
            if(i >= p.size()){
                freAnswer[s[i - p.size()] - 'a']--;
            }
            if(freAnswer == frep){
                answer.push_back(i - p.size() + 1);
            }
        }
        return answer;
    }
};