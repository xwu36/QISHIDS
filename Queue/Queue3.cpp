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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> que;
        TreeNode* cur;
        int len;
        
        que.push(root);
        
        while(!que.empty()){
            len = que.size();
            vector<int> temp;
            
            for(int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
                temp.push_back(cur->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
