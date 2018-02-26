class Solution {
public:
    const int VISITING = 1, VISITED = -1, NOT_VISITED = 0;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        construct_graph(graph, prerequisites);
        
        vector<int> timestamps;
        if(!topo_sort(graph, numCourses, timestamps)) return {};
        
        reverse(timestamps.begin(), timestamps.end());
        return timestamps;
    }
    
    void construct_graph(vector<vector<int>> &graph, const vector<pair<int, int>>& prerequisites){
        for(auto prereq : prerequisites){
            graph[prereq.second].push_back(prereq.first);
        }
    }
    
    bool topo_sort(const vector<vector<int>> &graph, int numCourses, vector<int> &timestamps){
        vector<int> visit_state(numCourses, NOT_VISITED);
        for(int i = 0; i < numCourses; i++){
            if(!visit_state[i])
                if(!dfs(graph, i, timestamps, visit_state)) return false;
        }
        return true;
    }
    
    bool dfs(const vector<vector<int>> &graph, int cur_node, vector<int> &timestamps, vector<int> &visit_state){
        visit_state[cur_node] = VISITING;
        for(auto neighbor : graph[cur_node]){
            if((visit_state[neighbor] == NOT_VISITED && !dfs(graph, neighbor, timestamps, visit_state))
               || visit_state[neighbor] == VISITING)
                return false;
        }
        visit_state[cur_node] = VISITED;
        timestamps.push_back(cur_node);
        return true;
    }
};
