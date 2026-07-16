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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        map<int,int>map;
        queue<TreeNode*>q;
        q.push(root);
        bool dir = true;
        vector<vector<int>>ans;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode *crr = q.front();
                q.pop();
                int idx = dir ? i : size - 1 -i;
                temp[idx] = crr->val;
                if(crr->left){
                    q.push(crr->left);
                }
                if(crr->right){
                    q.push(crr->right);
                }
            }
            ans.push_back(temp);
            dir = !dir;
        }
        return ans;
    }
};