class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
    
        queue<int> zeros;
        for(int i = 0; i < numCourses; i++){
            if(!degrees[i]) zeros.push(i);
        }
        
        vector<int> toposort;
        for(int i = 0; i < numCourses; i++){
            if(zeros.size() == 0) return {};
            int cur = zeros.front();
            toposort.push_back(cur);
            zeros.pop();
            unordered_set<int> neighbors = graph[cur];
            for(auto c : neighbors){
                degrees[c]--;
                if(degrees[c] == 0) zeros.push(c);
            }
        }
        return toposort;
    }
    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto c : prerequisites){
            graph[c.second].insert(c.first);
        }
        return graph;
    }
    
    vector<int> compute_indegree(vector<unordered_set<int>>& graph){
        vector<int> degree(graph.size(), 0);
        for(auto neighbors : graph){
            for(auto neigh : neighbors){
                degree[neigh]++;
            }
        }
        return degree;
    }
};
