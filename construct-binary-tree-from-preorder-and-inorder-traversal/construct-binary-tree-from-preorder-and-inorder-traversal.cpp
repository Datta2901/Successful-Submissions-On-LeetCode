/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
private:
    int index;
    int search(vector<int>&inorder,int start,int end,int val){
        for(int i = start; i <= end; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    // Start and end refers to the pointers in inorder
    TreeNode* BuildBinaryTree(vector<int>&inorder,vector<int>&preorder,int start,int end){
        if(start > end){
            return NULL;
        }
        int val = preorder[index]; 
        index++;
        TreeNode* root = new TreeNode(val);
        if(start == end){
            return root;
        }
        int pos = search(inorder,start,end,val);
        root->left = BuildBinaryTree(inorder,preorder,start,pos - 1);
        root->right = BuildBinaryTree(inorder,preorder,pos + 1,end);  
        return root;
    } 

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        if(inorder.size() != preorder.size()){
            return NULL;
        }
        return BuildBinaryTree(inorder,preorder,0,inorder.size() - 1);
    }

};