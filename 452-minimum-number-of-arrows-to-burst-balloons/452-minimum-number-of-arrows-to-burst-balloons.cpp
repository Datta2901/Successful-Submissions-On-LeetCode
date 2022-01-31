class Solution {
private:
    static bool cmp(vector<int>&p1,vector<int>&p2){
        return p1[1] < p2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int count = 1;
        int m = points.size();
        int arrow = points[0][1];
        for(int i = 1; i < m; i++){
            if(points[i][0] > arrow){
                count++;
                arrow = points[i][1];
            }
        }
        return count;
    }
};