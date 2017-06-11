/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return node;
        if(mymap.find(node) == mymap.end()){
            mymap[node] = new UndirectedGraphNode(node->label);
            vector<UndirectedGraphNode *> neighbs = node->neighbors;
            for(int i = 0; i < neighbs.size(); i++){
                mymap[node]->neighbors.push_back(cloneGraph(neighbs[i]));   
            }
        }
        return mymap[node];
    }
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mymap;
};
