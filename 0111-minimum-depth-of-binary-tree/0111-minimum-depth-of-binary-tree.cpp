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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        if(root->left == NULL){
            return 1 + rightHeight;
        }
        if(root->right == NULL){
            return 1 + leftHeight;
        }
        int depth = min(leftHeight, rightHeight) + 1;
        return depth;
    }
};