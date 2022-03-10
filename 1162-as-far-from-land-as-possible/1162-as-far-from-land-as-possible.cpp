class Solution {
    int m,n;
    void bfs(vector<vector<int> >&grid,int i,int j){
        
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int> > store;
        vector<vector<int> > distance(m,vector<int>(n,INT_MAX));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    distance[i][j] = 0;
                    store.push({i,j});
                }
            }
        }
        int answer = -1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!store.empty()){
            int X = store.front().first;
            int Y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || distance[newX][newY] != INT_MAX){
                    continue;
                }
                distance[newX][newY] = distance[X][Y] + 1;
                answer = max(answer,distance[newX][newY]);
                store.push({newX,newY});
            }
            
        }
        return answer;
        
    }
};