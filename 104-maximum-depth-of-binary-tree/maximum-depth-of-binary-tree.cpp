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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        int height = 0;
        q.push(root);
        while(!q.empty()){
            height++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* up = q.front();
                if(up->left){
                    q.push(up->left);
                }
                if(up->right){
                    q.push(up->right);
                }
                q.pop();
            }
        }
        return height;
    }
};