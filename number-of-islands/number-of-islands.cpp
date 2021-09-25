class Solution {
public:

    void bfs(vector<vector<char> >& grid,int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int> > store;
        store.push({i,j});
        while(!store.empty()){
            int size = store.size();
            while(size--){
                int X = store.front().first;
                int Y = store.front().second; 
                store.pop();
                int dx[4] = {0,0,1,-1};
                int dy[4] = {1,-1,0,0};
                for(int i = 0; i < 4; i++){
                    int nx = X + dx[i];
                    int ny = Y + dy[i];
                    if(nx >= m || ny >= n || nx < 0 || ny < 0 || grid[nx][ny] != '1'){
                        continue;
                    }
                    grid[nx][ny] = '2';
                    store.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    // cout << i << " " << j << endl;
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};