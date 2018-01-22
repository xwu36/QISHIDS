class my_hash {
public:
  size_t operator()(const vector<int> &vec) const {
      size_t seed = vec.size();
      for(auto& i : vec) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
  }
};

class Solution {
public:
    unordered_map<vector<int>, int, my_hash> memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs, needs.size());
    }
        
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int n){
        if(memo[needs] != 0)
            return memo[needs];
        
        int cost = 0;
        for(int i = 0; i < n; i++)
            cost += price[i] * needs[i];
        
        for(vector<int> combo : special){
            bool flag = true;
            for(int i = 0; i < n; i++){
                if(needs[i] - combo[i] < 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int i = 0; i < n; i++) needs[i] -= combo[i];
                cost = min(dfs(price, special, needs, n) + combo[n], cost);
                for(int i = 0; i < n; i++) needs[i] += combo[i];
            }
        }
        memo[needs] = cost;
        return cost;
    }
};
