// class Solution {
// public:
//     bool areAlmostEqual(string s1, string s2) {
//         int m = s1.size();
//         int n = s2.size();
//         int count = 0;
//         char p1 = ' ',p2 = ' ';
//         for(int i = 0; i < m; i++){
//             if(s1[i] != s2[i]){
//                 if(count == 0){
//                     p1 = s1[i];
//                     p2 = s2[i];
//                 }else{
//                     if(p1 != s2[i] || p2 != s1[i]){
//                         return false;
//                     }
//                 }
//                 count++;
//             }
//         }
//         return (count == 2 || count == 0) ? true : false;
//     }
// };

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        int count = 0;
        char a,b;
        for(int i = 0; i < m; i++){
            if(s1[i] != s2[i]){
                if(count == 0){
                    a = s1[i];
                    b = s2[i];
                }else if(a != s2[i] || b != s1[i]){
                    return false;
                }
                count++;
            }
        }
        if(count == 0 || count == 2){
            return true;
        }
        return false;
    }
};