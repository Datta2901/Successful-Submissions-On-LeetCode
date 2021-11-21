class Solution {
private:
    TreeNode* BuildBinaryTree(vector<int>&inorder,vector<int> &postorder,int is,int ie,int ps,int pe,unordered_map<int,int>&InorderIndex){
        if(ps > pe || is > ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = InorderIndex[postorder[pe]];
        int ns = inRoot - is; 
        root->left = BuildBinaryTree(inorder,postorder,is,inRoot - 1,ps,ps + ns - 1,InorderIndex);
        root->right = BuildBinaryTree(inorder,postorder,inRoot + 1,ie,ps + ns,pe - 1,InorderIndex);
        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        unordered_map<int,int>InorderIndex;
        for(int i = 0; i < inorder.size(); i++){
            InorderIndex[inorder[i]] = i;
        }
        return BuildBinaryTree(inorder,postorder,0,inorder.size() - 1,0,postorder.size() - 1,InorderIndex);
    }
};
