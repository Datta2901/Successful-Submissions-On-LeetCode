class Solution {
public:
    
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int,int> >answer;
        queue<pair<int,int> >possibility;
        map<pair<int,int>,int > visited;
        possibility.push({sr,sc});
        while(!possibility.empty()){
            pair<int,int>node =possibility.front();
            if(visited[node] == 0){
                // Up
                if(node.first + 1 < m && node.second < n){
                    if(image[node.first][node.second] == image[node.first + 1][node.second]){
                        possibility.push({node.first + 1,node.second});
                    }
                }
                // Down
                if(node.first - 1 >= 0 && node.first - 1 < m && node.second < n ){
                    if(image[node.first][node.second] == image[node.first - 1][node.second]){
                        possibility.push({node.first - 1,node.second});
                    }
                }

                // Left
                if(node.first  < m && node.second - 1 < n &&  node.second - 1 >= 0){
                    if(image[node.first][node.second] == image[node.first][node.second - 1]){
                        possibility.push({node.first,node.second - 1});
                    }
                }

                // Right
                if(node.first  < m && node.second + 1 < n){
                    if(image[node.first][node.second] == image[node.first][node.second + 1]){
                        possibility.push({node.first,node.second + 1});
                    }
                }
                visited[node] = 1;
                image[node.first][node.second] = newColor;
                // answer.push_back(node);
            }
            possibility.pop();   
        }
        return image;
    }
};



