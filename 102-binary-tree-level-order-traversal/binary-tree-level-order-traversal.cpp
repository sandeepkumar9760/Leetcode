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
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                TreeNode* crr = q.front();
                q.pop();
                temp.push_back(crr->val);
                if(crr->left){
                    q.push(crr->left);
                }
                if(crr->right){
                    q.push(crr->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};