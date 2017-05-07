class Solution {
public:
bool isValid(string s) {
        stack<char> mystack;
        for(int i = 0; i < s.size(); i++){
            char cur = s[i];
            if(cur == '(' || cur == '{' || cur == '[') mystack.push(cur);
            else if(mystack.size() == 0 && (cur == ')' || cur == '}' || cur == ']')) return false;
            else if(mystack.size() > 0){
                char top = mystack.top();
                if(top == '(' && cur == ')') mystack.pop();
                else if(top == '{' && cur == '}') mystack.pop();
                else if(top == '[' && cur == ']') mystack.pop();
                else return false;
            }
        }
        return mystack.size() == 0 ? true : false;
    }
};
