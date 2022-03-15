// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         unordered_map<char,int>fre;
//         vector<int>answer;
//         for(int i = 0; i < s.size(); i++){
//             fre[s[i]]++;
//         }
//         string ans = "";
//         for(int i = 0; i < s.size(); i++){
//             bool add = true;
//             if(fre[s[i]] - 1 == 0){
//                 ans += s[i];
//                 fre[s[i]]--;
//                 for(int i = 0; i < ans.size(); i++){
//                     if(fre[ans[i]] != 0){
//                         add = false;
//                         break;
//                     }
//                 }
//                 if(add){
//                     answer.push_back(ans.size());
//                     ans = "";
//                 }
//             }else{
//                 ans += s[i];
//                 fre[s[i]]--;
//             }
//         }
//         if(ans.size() > 0){
//             answer.push_back(ans.size());
//         }
//         return answer;
//     }
// };



class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int start = 0,end = 0;
        vector<int>fre(26, 0),answer;
        for(int i = 0; i < s.size(); i++){
            fre[s[i] - 'a'] = i;
        }
        int mini = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end,fre[s[i] - 'a']);
            if(i == end){
                answer.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return answer;
    }
};