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
vector<int> answer;
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    answer.push_back(root->val);
    inorder(root->right);
}

int count1;
TreeNode *a;
int i;
void Inorder(TreeNode *root, vector<int> &answer)
{
    if (count1 == 0)
    {
        a = root;
        count1++;
    }
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, answer);
    root->val = answer[i];
    i++;
    Inorder(root->right, answer);
}

void solve(TreeNode *root)
{
    answer.clear();
    count1 = 0;
    i = 0;
    a = NULL;
    inorder(root);
    int size = answer.size();
    vector<int> sorted = answer;
    sort(sorted.begin(), sorted.end());
    Inorder(root, sorted);
}

public:
    Solution(){
        i = 0;
        count1 = 0;
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        root = a;
    }
};