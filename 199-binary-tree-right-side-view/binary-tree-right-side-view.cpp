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
    void right_view(vector<int>&ans , TreeNode* node , int level){
        if(!node) return;
        if(level==ans.size()){
            ans.push_back(node->val);
        }
        right_view(ans,node->right,level+1);
        right_view(ans,node->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        right_view(ans,root,0);
        return ans;
    }
};