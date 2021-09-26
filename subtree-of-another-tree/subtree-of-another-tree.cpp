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
public:
    vector<int>Sub;
    bool isSame(TreeNode* r,TreeNode* s){
        if(s == NULL || r == NULL){
            return (s == NULL && r == NULL);
        }else if(s->val == r->val){
            return isSame(r->left,s->left) && isSame(r->right,s->right);
        }else{
            return false;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }else if(isSame(root,subRoot)){
            return true;
        }else{
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
    }
};