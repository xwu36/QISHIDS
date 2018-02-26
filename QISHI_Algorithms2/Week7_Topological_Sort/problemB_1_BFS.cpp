class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> incoming_degree(numCourses, 0);
        construct_graph(graph, prerequisites, incoming_degree);
        
        return topo_sort(graph, incoming_degree, numCourses);
    }
    
    void construct_graph(vector<vector<int>> &graph, const vector<pair<int, int>>& prerequisites, vector<int> &incoming_degree){
        for(auto prereq : prerequisites){
            graph[prereq.second].push_back(prereq.first);
            incoming_degree[prereq.first]++;
        }
    }
    
    vector<int> topo_sort(const vector<vector<int>> &graph, vector<int> &incoming_degree, int numCourses){
        queue<int> Q;
        for(int i = 0; i < numCourses; i++){
            if(!incoming_degree[i])
                Q.push(i);
        }
        if(Q.size() == 0) return {};
        vector<int> schedule;
        while(Q.size() > 0){
            int top = Q.front();
            Q.pop();
            schedule.push_back(top);
            for(auto neigh : graph[top])
                if(--incoming_degree[neigh] == 0)
                    Q.push(neigh);
        }
        return schedule.size() == numCourses ? schedule : vector<int>();
    }
};

