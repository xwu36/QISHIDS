class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        int height = getHeight(root);
        for(int i = 0; i < height; i++) list.add(new ArrayList<>());
        dfs(root, list, 0, height);
        return list;
    }
    
    public int getHeight(TreeNode root){
        return root == null ? 0 : Math.max(getHeight(root.left), getHeight(root.right)) + 1;
    }
    
    public void dfs(TreeNode root, List<List<Integer>> list, int layer, int height){
        if(root == null) return;
        list.get(height - layer - 1).add(root.val);
        dfs(root.left, list, layer + 1, height);
        dfs(root.right, list, layer + 1, height);
    }
}
