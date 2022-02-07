// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         map<char,int>fre;
//         for(auto it : s){
//             fre[it]++;
//         }
//         for(auto it : t){
//             fre[it]--;
//         }
//         for(auto it : fre){
//             // cout << it.first << " " << it.second << endl;
//             if(it.second < 0){
//                 return it.first;
//             }
//         }
//         return 'a';
//     }
// };

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.size();
        int i = 0;
        for(i = 0; i < n; i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }    
        if(i == n){
           return t[n]; 
        }
        return 'a';
    }
};