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
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(root == NULL) return result;
//         queue<TreeNode*> q;
//         q.push(root);
//         //q.push(NULL);
//         while(!q.empty()){
//             int size = q.size();
//             vector<int> n(size);
//             for(int i=0;i<size;i++){
//             TreeNode* temp = q.front();
//             n[i]= (temp->val);
//             q.pop();
           
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//             }
//             result.push_back(n);
//         }
//         return result;
//     }

    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> currVec;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                currVec.push_back(curr->val);
            
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
            }
            res.push_back(currVec);
        }
        return res;
    }
};