/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1 = p->val;
        int n2 = q->val;
        if(!root || root->val==n1 || root->val==n2){
            return root;
        }
        
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        TreeNode* left = lowestCommonAncestor(root->left,p,q);

        if(left==nullptr){
            return right;
        }
        if(right==nullptr){
            return left;
        }
        return root;
    }
};