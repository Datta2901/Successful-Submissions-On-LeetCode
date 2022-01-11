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
    int convertToDecimal(string bin){
        int deci = stoi(bin,0,2);
        return deci;
    }
    
    void getAnswer(TreeNode* root,string binary){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            answer += convertToDecimal(binary + to_string(root->val));
            return;
        }
        getAnswer(root->left,binary + to_string(root->val));
        getAnswer(root->right,binary + to_string(root->val));
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        answer = 0;
        getAnswer(root,"");
        return answer;
    }
};