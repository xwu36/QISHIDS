/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if(root == null) return 0;
        while(root != null){
            stack.push(root);
            root = root.left;
        }
        
        while(stack.size() > 0){
            TreeNode cur = stack.pop();
            if(--k == 0) return cur.val;
            if(cur.right != null){
                TreeNode curcur = cur.right;
                while(curcur != null){
                    stack.push(curcur);
                    curcur = curcur.left;
                }
            }
        }
        return 0;
    }
}

