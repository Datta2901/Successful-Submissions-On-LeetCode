class NumArray {
public:
    vector<int>Fen,arr;
    int size;

    void build(vector<int>nums){
        for(int i = 0; i < nums.size(); i++){
            Buildupdate(i,nums[i]);
        }
    }
    
    NumArray(vector<int>& nums){
        arr = nums;
        Fen.resize(nums.size() + 1);
        fill(Fen.begin(),Fen.end(),0);
        size = arr.size();
        build(nums);
    }
    
    void Buildupdate(int index, int val) {
        index += 1;
        while(index <= size){
            Fen[index] += val;
            index = index + (index & (-index));
        }
    }

    void update(int index, int val) {
        val = val - arr[index];
        arr[index] += val;
        index += 1;
        while(index <= size){
            Fen[index] += val;
            index = index + (index & (-index));
        }
    }
    
    int sumOneRange(int index){
        index += 1;
        int sum = 0;
        while(index > 0){
            sum += Fen[index];
            index -= (index & -index);
        }
        return sum;
    }

    int sumRange(int left, int right){
        int l = sumOneRange(left - 1);
        int r = sumOneRange(right);
        cout << l << " " << r << endl;
        return  r - l ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */