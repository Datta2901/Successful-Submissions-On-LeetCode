class MyHashSet {
private:
	vector<bool> mpp;
public:	
    MyHashSet(){
        vector<bool> dup(1e6 + 1,false);
        mpp = dup;
    }
	void add(int key) {
		mpp[key] = true;
	}
	
	void remove(int key) {
		mpp[key] = false;
	}
	
	bool contains(int key) {
		return mpp[key];
	}
};