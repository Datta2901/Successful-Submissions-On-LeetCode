class Solution {
    void Dikstra(vector<pair<int,int > >adj[],int source,vector<int>&distance){
        priority_queue<pair<int,int>,vector<pair<int,int > >,greater<pair<int,int> > > track;
        track.push({source,0});
        distance[source] = 0;
        while(!track.empty()){
            int node = track.top().first;
            int wt = track.top().second;
            track.pop();
            for(auto it : adj[node]){
                if(wt + it.second < distance[it.first]){
                    distance[it.first] = wt + it.second;
                    track.push({it.first,distance[it.first]});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>distance(n + 1,101);
        vector<pair<int,int > >adj[n + 1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }        
        Dikstra(adj,k,distance);
        int mini = INT_MIN;
        for(int i = 1; i <= n; i++){
            int it = distance[i];
            cout << it << " ";
            mini = max(mini,it);
        }
        if(mini == 101){
            return -1;
        }
        return mini;
    }
};