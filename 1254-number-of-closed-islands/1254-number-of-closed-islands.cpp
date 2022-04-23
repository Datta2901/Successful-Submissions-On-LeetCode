// class Solution {
// private:
//     int count;
//      int m;
//      int n;
//     void bfs(vector<vector<int> >&grid,int X,int Y){
//         queue<pair<int,int> > store;
//         store.push({X,Y});
//         int dx[4] = {0,0,1,-1};
//         int dy[4] = {1,-1,0,0};
//         while(!store.empty()){
//             X = store.front().first;
//             Y = store.front().second;
//             store.pop();
//             for(int i = 0; i < 4; i++){
//                 int x = X + dx[i];
//                 int y = Y + dy[i];
//                 if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0){
//                     continue;
//                 }
//                 grid[x][y] = 2;
//                 store.push({x,y});
//             }
//         }  
//     }
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         count = 0;
//         m = grid.size();
//         n = grid[0].size();
//         int corners = 0;
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 0){
//                     bfs(grid,i,j);
//                 }
//             }
//         }
        
//         for(int i = 1; i < m - 1; i++){
//             for(int j = 1; j < n - 1; j++){
//                 if(grid[i][j] == 0){
//                     bfs(grid,i,j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// class Solution {
//     int m,n;
//     bool dfs(vector<vector<int> > &grid,int i,int j){
//         if(i < 0 || i >= m || j < 0 || j >= n){
//             return false;
//         }
//         if(grid[i][j] == 1){
//             return true;
//         }
//         grid[i][j] = 1;
//         bool one = dfs(grid,i,j + 1);
//         bool two = dfs(grid,i,j - 1);
//         bool three = dfs(grid,i + 1,j);
//         bool four = dfs(grid,i - 1,j);
//         return one && two && three && four;
//     }
    
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int count = 0;
//         m = grid.size();
//         n = grid[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 0){
//                     if(dfs(grid,i,j)){
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
private:
    int m,n;
    void bfs(vector<vector<int> >&grid,int X,int Y){
        queue<pair<int,int> > store;
        store.push({X,Y});
        grid[X][Y] = 2;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!store.empty()){
            int x = store.front().first;
            int y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0){
                    continue;
                }
                grid[newX][newY] = 2;
                store.push({newX,newY});
            }
        }        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int answer = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 0){
                    bfs(grid,i,j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    bfs(grid,i,j);
                    answer++;
                }
            }
        }
        return answer;
    }
};