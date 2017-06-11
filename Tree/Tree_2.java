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
    public TreeNode sortedArrayToBST(int[] nums) {
        return convertArrayToBST(nums, 0, nums.length);
    }
    
    private TreeNode convertArrayToBST(int[] nums, int l, int r){
        int m = l + (r - l) / 2;
        if(l > r || m >= nums.length || m < 0) return null;
        TreeNode root = new TreeNode(nums[m]);
        root.left = convertArrayToBST(nums, l, m - 1);
        root.right = convertArrayToBST(nums, m + 1, r);
        return root;
    }
}

// 0 1 2 3 4
// 0 1 - 3 4
// 
