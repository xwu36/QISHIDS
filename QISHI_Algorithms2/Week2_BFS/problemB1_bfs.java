class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null) return new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<List<Integer>> list = new ArrayList<>();
        int layer = 0;
        while(queue.size() > 0){
            int queue_size = queue.size();
            list.add(new ArrayList<>());
            for(int i = 0; i < queue_size; i++){
                TreeNode top = queue.poll();
                list.get(layer).add(top.val);
                if(top.left != null) queue.add(top.left);
                if(top.right != null) queue.add(top.right);
            }
            layer++;
        }
        Collections.reverse(list);
        return list;
    }
}
