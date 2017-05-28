public class Solution {
    public int singleNumber(int[] A) {
        Map<Integer, Integer> frequenceMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < A.length; i++) frequenceMap.put(A[i], frequenceMap.getOrDefault(A[i], 0) + 1);
        for(int key : frequenceMap.keySet()) 
            if(frequenceMap.get(key) == 1) 
                return key;
        return -1;
    }
}
