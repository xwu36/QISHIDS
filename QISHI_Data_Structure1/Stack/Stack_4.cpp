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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode* > stack1;
        if(root == nullptr) return result;
        stack1.push(root);
        while(stack1.size() > 0){
            TreeNode* temp = stack1.top();
            stack1.pop();
            result.push_back(temp->val);
            if(temp->right != nullptr) stack1.push(temp->right);
            if(temp->left != nullptr) stack1.push(temp->left);
        }
        return result;
    }
};
