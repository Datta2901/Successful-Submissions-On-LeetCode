
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> fre;
//         priority_queue<pair<int,char> > pq; 
//         for(auto it : s){
//             fre[it]++;
//         }
//         for(auto it : fre){
//             pq.push({it.second,it.first});
//         }
//         string answer = "";
//         while(!pq.empty()){
//             answer += string(pq.top().first,pq.top().second);
//             pq.pop();
//         }
//         return answer;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> fre;
        priority_queue<pair<int,char> > pq; 
        for(auto it : s){
            fre[it]++;
        }
        for(auto it : fre){
            pq.push({it.second,it.first});
        }
        string answer = "";
        while(!pq.empty()){
            for(int i = 0; i < pq.top().first; i++){
                answer += pq.top().second;
            }
            pq.pop();
        }
        return answer;
    }
};





