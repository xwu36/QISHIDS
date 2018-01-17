class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //construct a graph like this 0-->1-->2
        //which means you have to take 0 before taking 1, and you have to take 1 before taking 2.
        //also we need to record how many nodes pointing to each onde
        int[] inComingDegrees = new int[numCourses];
        Set<Integer>[] graph = new Set[numCourses];
        buildGraph(numCourses, prerequisites, inComingDegrees, graph);
        
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(inComingDegrees[i] == 0)
                heap.add(i);
        }
        if(heap.size() == 0) return false;
        while(heap.size() > 0){
            int top = heap.poll();
            count++;
            if(graph[top] == null) continue;
            for(int neigh : graph[top]){
                if(--inComingDegrees[neigh] == 0)
                    heap.add(neigh);
            }
        }
        return count == numCourses;
    }
    
    public void buildGraph(int numCourses, int[][] prerequisites, int[] inComingDegrees, Set<Integer>[] graph){
        for(int[] pre : prerequisites){
            if(graph[pre[1]] == null)
                graph[pre[1]] = new TreeSet<>();
            graph[pre[1]].add(pre[0]);
            inComingDegrees[pre[0]]++;
        }
    }
}
