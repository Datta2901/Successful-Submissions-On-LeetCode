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
    int levelOrder(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*,int> >level;
        level.push({root,0});
        int width = 0;
        while(!level.empty()){
            int size = level.size();
            int maxi = INT_MIN;
            int mini = INT_MAX;
            while(size--){
                TreeNode* node= level.front().first;
                int ind = level.front().second;
                maxi = max(maxi,ind);
                mini = min(mini,ind);
                level.pop();
                if(node->left){
                    long long i = (long long)2 * ind + 1;
                    level.push({node->left,i});
                }
                if(node->right){
                    long long i = (long long)2 * ind + 2;
                    level.push({node->right,i});
                }
            }
            width = max(width,maxi - mini + 1);
        }
        return width;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrder(root);
    }
};