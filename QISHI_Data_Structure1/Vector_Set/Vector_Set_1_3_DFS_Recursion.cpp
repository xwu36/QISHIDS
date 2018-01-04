/*
 * DFS Solution using Recursion to Problem 1.3
 * by Xiaoxin Wu
 * 04/17/17
 * */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
void dfs(vector<int> neighbors[], int cur, unordered_set<int>& visited);

int main() {
    vector<int> neighbors[7];
    neighbors[0] = {1, 2};
    neighbors[1] = {0, 2, 3, 4, 6};
    neighbors[2] = {0, 1};
    neighbors[3] = {1, 5};
    neighbors[4] = {1, 5};
    neighbors[5] = {3, 4};
    neighbors[6] = {1};
    unordered_set<int> visited;

    dfs(neighbors, 0, visited);
    return 0;
}

void dfs(vector<int> neighbors[], int cur, unordered_set<int>& visited){
    for(auto n : neighbors[cur]){
        if(visited.find(n) == visited.end()){
            cout << n << endl;
            visited.insert(n);
            dfs(neighbors, n, visited);
        }
    }
}
