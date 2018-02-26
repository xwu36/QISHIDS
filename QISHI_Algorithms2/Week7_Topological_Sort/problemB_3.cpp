class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> incoming_degree;
        unordered_set<char> letters;
        for(const auto &word: words){
            for(int i = 0; i < word.size(); i++)
                letters.insert(word[i]);
        }
        construct_graph(words, words.size(), graph, incoming_degree);
        return topo_sort(graph, incoming_degree, letters);
    }
    
    void construct_graph(const vector<string>& words, int n, unordered_map<char, vector<char>> &graph, unordered_map<char, int> &incoming_degree){
        for(int i = 1; i < n; i++){
            int a = 0;
            for(; a < words[i].size() && words[i][a] == words[i - 1][a]; a++){}
            if(a < words[i - 1].size()){
                graph[words[i - 1][a]].push_back(words[i][a]);
                incoming_degree[words[i][a]]++;
            }
        }
    }
    
    string topo_sort(unordered_map<char, vector<char>> &graph, unordered_map<char, int> &incoming_degree, unordered_set<char> &letters){
        queue<char> Q;
        for(auto lt : letters){
            if(incoming_degree.find(lt) == incoming_degree.end())
                Q.push(lt);
        }
        string s;
        while(Q.size() > 0){
            char top = Q.front();
            s.push_back(top);
            Q.pop();
            for(auto neigh : graph[top]){
                if(--incoming_degree[neigh] == 0)
                    Q.push(neigh);
            }
        }
        return s.size() == letters.size() ? s : "";
    }
};
