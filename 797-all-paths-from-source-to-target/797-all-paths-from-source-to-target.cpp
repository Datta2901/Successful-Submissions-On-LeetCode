class Solution {
    vector<vector<int> > answer;
    void bfs(vector<vector<int> > &graph){
        queue<vector<int> > store;
        store.push({0});
        while(!store.empty()){
            vector<int> path = store.front();
            store.pop();
            int node = path[path.size() - 1];
            for(auto it : graph[node]){
                path.push_back(it);
                if(it == graph.size() - 1){
                    answer.push_back(path);
                }else{
                    store.push(path);
                }
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        bfs(graph);
        return answer;
    }
};