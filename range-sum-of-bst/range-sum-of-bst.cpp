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
    int answer;
    void inorder(TreeNode* root,int low,int high){
        if(root == NULL){
            return;
        }
        if(low <= root->val && root->val <= high){
            answer += root->val;
        }
        inorder(root->left,low,high);
        inorder(root->right,low,high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        answer = 0;
        inorder(root,low,high);
        return answer;
    }
};