class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(beginWord.equals(endWord) || wordList.size() == 0) return 0;
        Set<String> wordSet = new HashSet<>(wordList);
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        visited.add(beginWord);
        int layer = 0;
        while(queue.size() > 0){
            int q_size = queue.size();
            for(int i = 0; i < q_size; i++){
                String cur = queue.poll();
                if(cur.equals(endWord))
                    return layer + 1;
                pushNextLayerToSet(cur, wordSet, visited, queue);
            }
            layer++;
        }
        return 0;
    }
    
    public void pushNextLayerToSet(String cur, Set<String> wordSet, Set<String> visited, Queue<String> queue){
        char[] charArr = cur.toCharArray();
        for(int i = 0; i < charArr.length; i++){
            char temp = charArr[i];
            for(int j = 0; j < 26; j++){
                charArr[i] = (char)('a' + j);
                String replaced_cur = new String(charArr);
                if(!replaced_cur.equals(cur) && wordSet.contains(replaced_cur) && !visited.contains(replaced_cur)){
                    queue.add(replaced_cur);
                    visited.add(replaced_cur);
                }
            }
            charArr[i] = temp;
        }
    }
}
