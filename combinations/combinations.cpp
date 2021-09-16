class Solution {
public:
    vector<vector<int> > result;
    
    void GeneratePossibleCombinations(int index,int n,vector<int>&current,int k){
        if(current.size() == k){
            result.push_back(current);
            return ;
        }
        for(int i = index; i <= n; i++){
            current.push_back(i);
            GeneratePossibleCombinations(i + 1,n,current,k);
            current.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<int>current;
        GeneratePossibleCombinations(1,n,current,k);
        return result;
    }
};