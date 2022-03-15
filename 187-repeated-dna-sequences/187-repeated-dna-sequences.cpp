// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<string,int>fre;
//         for(int i=0;i<s.size();i++){
//             if((i+10)>s.size()){
//                 break;
//             }
//             string a=s.substr(i,10);
//             fre[a]++;
//         }
//         vector<string>answer;
//         for(auto x: fre){
//             if(x.second>1){
//                 answer.push_back(x.first);

//             }
//         }
//     return answer;
//     }
// };

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>fre;
        string a;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(i + 10 <= n){
                a = s.substr(i,10);
                fre[a]++;
            }
        }
        vector<string>answer;
        for(auto it : fre){
            if(it.second > 1){
                answer.push_back(it.first);
            }
        }
        return answer;
    }
};