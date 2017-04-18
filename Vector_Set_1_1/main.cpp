#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> vec = {1, 5, 2, 1, 4, 3, -1, 7, 2, 8, 9, 5};
    unordered_set<int> visited;
    /*
     * Traverse the vec, use HashSet to check if the element is not visited, put it into the HashSet,
     * otherwise, print out this visited element
     * */
    for(auto v : vec){
        if(visited.find(v) == visited.end()) visited.insert(v);
        else cout << v << endl;
    }
    return 0;
}
