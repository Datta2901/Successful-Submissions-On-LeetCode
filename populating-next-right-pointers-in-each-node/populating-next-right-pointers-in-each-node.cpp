/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //Level Order Traversal of a tree;
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*>track;
        track.push(root);
        track.push(NULL);
        while(!track.empty()){
            Node* node = track.front();
            track.pop();
            if(node == NULL && track.empty()){
                return root;
            }else if(node == NULL){
                track.push(node);
            }else if(node){
                node->next = track.front();
                if(node->left){
                    track.push(node->left);
                }if(node->right){
                    track.push(node->right);
                }
            }
        }
        return root;
    }
};