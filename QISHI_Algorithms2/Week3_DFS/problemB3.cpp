class TrieNode{
public:
    TrieNode *children[26];
    bool isWord = false;
    string word = "";
    
    ~TrieNode(){
        for(auto i=0; i<26; ++i) delete children[i];
    }
};

class TrieTree{
public:
    TrieNode *root = new TrieNode();
    
    void buildTree(vector<string>& words){
        for(auto word : words){
            TrieNode *cur = root;
            for(char c : word){
                if(cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->isWord = true;
            cur->word = word;
        }
    }
    
    ~TrieTree() { delete root; }
};

class Solution {
public:
    int ds[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        TrieTree *tree = new TrieTree();
        tree->buildTree(words);
        unordered_set<string> hash;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(tree->root->children[board[i][j] - 'a'] != nullptr){
                    unordered_set<string> tmp = dfs(board, i, j, n, m, tree->root->children[board[i][j] - 'a']);
                    hash.insert(tmp.begin(), tmp.end());
                }
            }
        }
        return vector<string>(hash.begin(), hash.end());
    }
    
    unordered_set<string> dfs(vector<vector<char>>& board, int i, int j, int n, int m, TrieNode *root){
        unordered_set<string> hash;
        if(root == nullptr) return hash;
        if(root->isWord){
            hash.insert(root->word);
        }
        char origin = board[i][j];
        board[i][j] = '#';
        for(auto d : ds){
            int cur_i = i + d[0];
            int cur_j = j + d[1];
            if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m || board[cur_i][cur_j] == '#')
                continue;
            unordered_set<string> tmp = dfs(board, cur_i, cur_j, n, m, root->children[board[cur_i][cur_j] - 'a']);
            hash.insert(tmp.begin(), tmp.end());
        }
        board[i][j] = origin;
        return hash;
    }
};
