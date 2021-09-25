class Solution {
public:

    void dfs(vector<int>adj[],vector<bool>&visited,int n){
        stack<int>store;
        store.push(n);
        while(!store.empty()){
            int city = store.top();
            store.pop();
            for(auto it : adj[city]){
                if(!visited[it]){
                    visited[it] = true;
                    store.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int> >&isConnected) {
        

        int n = isConnected.size();
        vector<int> adj[n + 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    if(i != j)
                        adj[i + 1].push_back(j + 1);
                }
            }
        }

        // for(int i = 1; i <= n; i++){
        //     cout << i << " -> ";
        //     for(auto j : adj[i]){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        int count = 0;
        vector<bool>visited(n + 1,false);
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};