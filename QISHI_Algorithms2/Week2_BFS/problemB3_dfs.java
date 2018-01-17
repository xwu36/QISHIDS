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
        
        Set<String> set = new HashSet<>();
        dfs(s, n, 0, invalid_left, invalid_right, 0, "", set);
        return new ArrayList<>(set);
    }
    
    public void dfs(String s, int n, int sp, int invalid_left, int invalid_right, int pair, String path, Set<String> set){
        if(sp == n){
            if(invalid_left == 0 && invalid_right == 0 && pair == 0)
                set.add(path);
            return;
        }
        
        if(s.charAt(sp) == '(' || s.charAt(sp) == ')'){
            if(s.charAt(sp) == '('){
                //include this '('
                dfs(s, n, sp + 1, invalid_left, invalid_right, pair + 1, path + "(", set);
                //exculde this '('
                if(invalid_left > 0)
                    dfs(s, n, sp + 1, invalid_left - 1, invalid_right, pair, path, set);
            }else{
                //include this ')', to form a pair, we have to make sure we have unpaired '(' before
                if(pair > 0)
                    dfs(s, n, sp + 1, invalid_left, invalid_right, pair - 1, path + ")", set);
                //exculde this ')'
                if(invalid_right > 0)
                    dfs(s, n, sp + 1, invalid_left, invalid_right - 1, pair, path, set);
            }    
        }else{
            dfs(s, n, sp + 1, invalid_left, invalid_right, pair, path + s.charAt(sp), set);
        }
    }
}
