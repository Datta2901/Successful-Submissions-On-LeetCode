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
    
    bool isFound(TreeNode* root,int k,set<int>&answer){
        if(root == NULL){
            return false;
        }
        if(answer.find(k - root->val) != answer.end()){
            return true;
        }else{
            answer.insert(root->val);
        }
        
        return isFound(root->left,k,answer) || isFound(root->right,k,answer);
        
    }
    
    bool findTarget(TreeNode* root, int k){
        set<int>answer;
        return isFound(root,k,answer);
    }
};