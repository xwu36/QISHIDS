class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    void dfs(string &s, int n, int sbeg, vector<vector<string>>& res, vector<string>& path){
        if(n == sbeg){
            res.push_back(vector<string>(path));
            return;
        }

        for(int i = sbeg; i < n; ++i){
            if(is_palindrome(s, sbeg, i)){
                string sub_s = s.substr(sbeg, i + 1 - sbeg);
                path.push_back(sub_s);
                dfs(s, n, i + 1, res, path);
                path.pop_back();
            }
        }
    }
    
    bool is_palindrome(string& s, int sbeg, int send){
        while(sbeg < send){
            if(s[sbeg++] != s[send--]) return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, s.size(), 0, res, path);
        return res;
    }
    
};
