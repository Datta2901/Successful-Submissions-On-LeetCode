// class Solution {
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int n = words.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             auto it = words[i].find(pref);
//             if(it == 0){
//                 count++;
//             }
//         }
//        return count; 
//     }
// };

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            string st = words[i].substr(0,pref.size());
            if(st == pref){
                count++;
            }
        }
       return count; 
    }
};