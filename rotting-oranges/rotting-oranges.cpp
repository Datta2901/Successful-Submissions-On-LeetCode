class node{
    public:
    int x,y,time;
    node(int _x,int _y,int _time){
        x = _x;
        y = _y;
        time = _time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int TotalOranges = 0;
        queue<node>track;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    track.push(node(i,j,0));
                }if(grid[i][j] != 0){
                    TotalOranges++;
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};  
        int count = 0;
        int maxTime = 0;
        while(!track.empty()){
            int x = track.front().x;
            int y = track.front().y;
            int time = track.front().time;
            track.pop();
            maxTime = max(maxTime,time);
            count++;
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 1){
                    continue;
                }
                track.push(node(newX,newY,time + 1));
                grid[newX][newY] = 2;
            }
        }

        if(count == TotalOranges){
            return maxTime;
        }
        return -1;
        }
};