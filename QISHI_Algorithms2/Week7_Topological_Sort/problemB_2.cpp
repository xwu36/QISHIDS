class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> incoming_degree(n + 1, 0);
        if(!construct_graph(graph, seqs, incoming_degree, n)) return false;
        
        return topo_sort(graph, incoming_degree, n, org);
        return true;
    }
    
    bool construct_graph(vector<vector<int>> &graph, const vector<vector<int>>& seqs, vector<int> &incoming_degree, int n){
        bool flag = false;
        for(auto seq : seqs){
            if(seq.size() >= 1){
                if(seq[0] > n || seq[0] < 0) return false;
                flag = true;
                if(seq.size() > 1){
                    for(int i = 1; i < seq.size(); i++){
                        if(seq[i] > n || seq[i] < 0) return false;
                        graph[seq[i - 1]].push_back(seq[i]);
                        incoming_degree[seq[i]]++;
                    }
                }
            }
        }
        return flag;
    }
    
    bool topo_sort(const vector<vector<int>> &graph, vector<int> &incoming_degree, int n, const vector<int>& org){
        queue<int> Q;
        for(int i = 1; i <= n; i++){
            if(!incoming_degree[i])
                Q.push(i);
        }
        vector<int> schedule;
        int count = 0;
        while(Q.size() == 1){
            int top = Q.front();
            Q.pop();
            if(org[count++] != top) return false;
            schedule.push_back(top);
            for(auto neigh : graph[top])
                if(--incoming_degree[neigh] == 0)
                    Q.push(neigh);
        }
        return count == org.size() ? true : false;
    }
};

