// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int res = 1;
//         int row = grid.size();
//         if (row == 0) return -1;
//         int col = grid[0].size();
//         if (col == 0 ) return -1;
//         if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

//             queue<pair<int, int>> queue;
//             queue.push(make_pair(0,0));
//             vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
//             grid[0][0] = 1;
//             while(!queue.empty()){
//                 int size = queue.size();
//                 while(size--){
//                     auto curr = queue.front();
//                     int x = curr.first, y = curr.second;
//                     queue.pop();
//                     if( x == row -1 && y == col -1) return grid[x][y];
//                     for(auto direction : directions){
//                         int nx = x + direction[0];
//                         int ny = y + direction[1];
//                         if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
//                             queue.push(make_pair(nx,ny));
//                             grid[nx][ny] = grid[x][y] + 1;
//                         }
//                     }
//                 }
//             }
//             return -1;
//         }
// };


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m - 1][n - 1] == 1 || grid[0][0] == 1){
            return -1;
        }
        queue<pair<int,int> > store;
        store.push({0,0});    
        grid[0][0] = 1;
        int dx[8] = {1,-1,0,0,1,1,-1,-1};
        int dy[8] = {0,0,-1,1,1,-1,1,-1};
        while(!store.empty()){
            int size = store.size();
            while(size--){
                int X = store.front().first;
                int Y = store.front().second;
                store.pop();
                if(X == m - 1 && Y == n - 1){
                    return grid[X][Y];
                }
                for(int i = 0; i < 8; i++){
                    int x = X + dx[i];
                    int y = Y + dy[i];
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0){
                        continue;
                    }
                    grid[x][y] = 1 + grid[X][Y];
                    store.push({x,y});
                }                
            }
        }
        return -1;
     }
};

































