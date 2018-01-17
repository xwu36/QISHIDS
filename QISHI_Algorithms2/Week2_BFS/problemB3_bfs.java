class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int n = s.length();
        
        //count the number of invalid parentheses
        int invalid_left = 0;
        int invalid_right = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(') invalid_left++;
            if(s.charAt(i) == ')'){
                if(invalid_left > 0) invalid_left--;
                else invalid_right++;
            }
        }
        
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0, "", invalid_left, invalid_right));
        for(int i = 0; i < n; i++){
            char cur = s.charAt(i);
            int queue_size = queue.size();
            for(int j = 0; j < queue_size; j++){
                Node node = queue.poll();
                if(cur == '(' || cur == ')'){
                    if(cur == '('){
                        queue.add(new Node(node.left_count + 1, node.path + cur, node.invalid_left, node.invalid_right));
                        if(node.invalid_left > 0)
                            queue.add(new Node(node.left_count, node.path, node.invalid_left - 1, node.invalid_right));
                    }else{
                        if(node.left_count > 0)
                            queue.add(new Node(node.left_count - 1, node.path + cur, node.invalid_left, node.invalid_right));
                        if(node.invalid_right > 0)
                            queue.add(new Node(node.left_count, node.path, node.invalid_left, node.invalid_right - 1));
                    }
                }else{
                    queue.add(new Node(node.left_count, node.path + cur, node.invalid_left, node.invalid_right));
                }
            }
        }
        
        Set<String> result = new HashSet<>();
        while(queue.size() > 0){
            Node node = queue.poll();
            if(node.left_count == 0)
                result.add(node.path);
        }
        return new ArrayList<>(result);
    }
    
    class Node{
        int left_count;
        int invalid_left;
        int invalid_right;
        String path;
        Node(int left_count, String path, int invalid_left, int invalid_right){
            this.left_count = left_count;
            this.path = path;
            this.invalid_left = invalid_left;
            this.invalid_right = invalid_right;
        }
    }
}
