/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) return "null";
        return root.val + "#" + serialize(root.left) + "#" + serialize(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        return deserializeTree(new StringBuilder(data));
    }
    
    public TreeNode deserializeTree(StringBuilder data) {
        System.out.println(data);
        if(data.length() == 0) return null;
        String cur = getNext(data);
        if(!cur.equals("null")){
            TreeNode tmp = new TreeNode(Integer.parseInt(cur));
            tmp.left = deserializeTree(data);
            tmp.right = deserializeTree(data);
            return tmp;
        }
        return null;
    }
    
    public String getNext(StringBuilder data){
        int ps = data.indexOf("#");
        if(ps == -1) ps = data.length();
        String res = data.substring(0, ps);
        data.delete(0, ps+1);
        return res;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));

//1
//2 1
//1
//
