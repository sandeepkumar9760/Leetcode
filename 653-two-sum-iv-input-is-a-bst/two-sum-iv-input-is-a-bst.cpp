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
class BSTIterator{
    stack<TreeNode*>st;
    bool reverse = true;
public:
    BSTIterator(TreeNode* node , bool isreverse){
        reverse = isreverse;
        push_all(node);
    }
    int next(){
        if(st.empty()) return -1;
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse){
            push_all(temp->right);
        }else{
            push_all(temp->left);
        }
        return temp->val;
    }
private:
    void push_all(TreeNode* node){
        while(node){
            st.push(node);
            if(!reverse){
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if (i+j<k) i = l.next();
            else j=r.next();
        }
        return false;
    }
};