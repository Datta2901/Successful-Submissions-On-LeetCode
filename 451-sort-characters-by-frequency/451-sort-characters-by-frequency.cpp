// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> freq;           
//         priority_queue<pair<int,char>> maxheap; 
//         for(char c: s)
//             freq[c]++;
//         for(auto it: freq)
//             maxheap.push({it.second,it.first}); 
//         s="";   
//         while(!maxheap.empty()){
//             s+=string(maxheap.top().first,maxheap.top().second); 
//             cout << s << endl;
//             maxheap.pop();
//         }
//         return s;
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
            answer += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return answer;
    }
};


