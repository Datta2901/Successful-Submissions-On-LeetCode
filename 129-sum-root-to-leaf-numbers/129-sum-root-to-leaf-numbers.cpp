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
    int answer = 0;
    
    void getAnswer(TreeNode* root,int index){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            answer += (index * 10 ) + root->val;
            return;
        }
        getAnswer(root->left,index * 10 + root->val);
        getAnswer(root->right,index * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        getAnswer(root,0);
        return answer;
    }
};