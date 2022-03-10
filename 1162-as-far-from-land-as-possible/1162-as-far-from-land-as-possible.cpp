// class Solution {
//     int m,n;
// public:
//     int maxDistance(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         queue<pair<int,int> > store;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 1){
//                     distance[i][j] = 0;
//                     store.push({i,j});
//                 }
//             }
//         }
//         int answer = -1;
//         int dx[4] = {0,0,1,-1};
//         int dy[4] = {1,-1,0,0};
//         while(!store.empty()){
//             int X = store.front().first;
//             int Y = store.front().second;
//             store.pop();
//             for(int i = 0; i < 4; i++){
//                 int newX = X + dx[i];
//                 int newY = Y + dy[i];
//                 if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0){
//                     continue;
//                 }
//                 distance[newX][newY] = distance[X][Y] + 1;
//                 answer = max(answer,distance[newX][newY]);
//                 store.push({newX,newY});
//             }
            
//         }
//         return answer;
        
//     }
// };

class Solution {
    int m,n;
public:
    int maxDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int> > store;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    store.push({i,j});
                }
            }
        }
        int answer = -1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int count = -1;
        while(!store.empty()){
            count++;
            int size = store.size();
            while(size--){
                int X = store.front().first;
                int Y = store.front().second;
                store.pop();
                for(int i = 0; i < 4; i++){
                    int newX = X + dx[i];
                    int newY = Y + dy[i];
                    if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0){
                        continue;
                    }
                    grid[newX][newY] = 2;
                    store.push({newX,newY});
                }
            }
            
        }
        if(count == 0){
            return -1;
        }
        return count;
        
    }
};