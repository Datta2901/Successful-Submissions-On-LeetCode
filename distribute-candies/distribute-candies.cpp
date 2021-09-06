class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>temp;
        for(int i = 0; i < candyType.size(); i++){
            temp.insert(candyType[i]);
        }
        int size = candyType.size()/2,answer;
        if(size >= temp.size()){
            answer = temp.size();
        }else{
            answer = size;
        }
        return answer;
    }
};