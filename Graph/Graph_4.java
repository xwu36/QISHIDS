class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty()) return 0;
        unordered_map<int, int> mymap;
        int maxlen = 0;
        for(auto i : num){
            if(mymap[i]) continue;
            mymap[i] = mymap[i - mymap[i-1]] = mymap[i + mymap[i+1]] = mymap[i-1] + mymap[i+1] + 1;
            maxlen = max(mymap[i], maxlen);
        }
        return maxlen;
    }
};
