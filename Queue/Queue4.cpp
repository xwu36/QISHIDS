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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        int len, depth = 0;
        TreeNode* cur;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            len = que.size();
            vector<int> temp;
            
            for(int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
            }
            
            if(depth++ % 2 == 1) reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};
