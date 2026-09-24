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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* up = q.front();
                temp.push_back(up->val);
                if(up->left){
                    q.push(up->left);
                }
                if(up->right){
                    q.push(up->right);
                }
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};