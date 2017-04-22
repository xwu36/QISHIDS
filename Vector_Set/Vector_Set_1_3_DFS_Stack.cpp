/*
 * DFS Solution using Stack to Problem 1.3
 * by Xiaoxin Wu
 * 04/17/17
 * */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

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
    stack<int> s;
    s.push(0);
    visited.insert(0);
    while(s.size() > 0){
        int cur = s.top();
        cout << cur << endl;
        s.pop();
        for(auto n : neighbors[cur]){
            if(visited.find(n) == visited.end()){
                s.push(n);
                visited.insert(n);
            }
        }
    }
    return 0;
}
