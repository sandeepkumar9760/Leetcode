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
    bool check(TreeNode* root , int crr_sum , int target_sum){
        if(!root) return false;
        crr_sum+=root->val;
        // if(crr_sumtarget_sum) return false;
        if(crr_sum==target_sum && !root->left && !root->right) return true;
        return check(root->left,crr_sum,target_sum) || check(root->right,crr_sum,target_sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        // if(root->val==targetSum && (root->left || root->right)) return false;
        return(check(root,0,targetSum));
    }
};