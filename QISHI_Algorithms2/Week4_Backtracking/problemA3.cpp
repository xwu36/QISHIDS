class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        generateParenthesis(n * 2, 0, res, path);
        return res;
    }
    
    void generateParenthesis(int n, int unpaired, vector<string>& res, string& path){
        if(n == 0){
            if(unpaired == 0) res.push_back(string(path));
            return;
        }
        
        if(n < unpaired) return;
        
        path.push_back('(');
        generateParenthesis(n - 1, unpaired + 1, res, path);
        path.pop_back();
        
        if(unpaired > 0){
            path.push_back(')');
            generateParenthesis(n - 1, unpaired - 1, res, path);
            path.pop_back();
        }
    }
};
