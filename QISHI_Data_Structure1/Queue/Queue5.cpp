class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //set<string> wordSet(wordList.begin(), wordList.end());
        vector<string>::iterator it;
        queue<string> que;
        
        que.push(beginWord);
        int len, res = 1;
        
        while(!que.empty()){
            len = que.size();
            for(int i = 0; i < len; i++){
                string s = que.front();
                que.pop();
                
                for(it = wordList.begin(); it != wordList.end(); it++){
                    string word = *it;
                    if(oneDifference(word, s)){
                        if(word == endWord) return res + 1;
                        wordList.erase(it);
                        que.push(word);
                        it--;
                        if(wordList.empty()) return false;                  
                    }
                }
            }
            res++;
        }
        return 0;
    }
    
    bool oneDifference(string& s1, string& s2){
        if(s1.size() != s2.size()) return 0;
        int res = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) res++;
            if(res > 1) return false;
        }
        return res;
    }
};
