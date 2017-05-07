class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> my_stack;
        int num1, num2, num3;
        for(auto v : tokens){
            if(v == "+" || v == "-" || v == "*" || v == "/"){
                num1 = my_stack.top();
                my_stack.pop();
                num2 = my_stack.top();
                my_stack.pop();
                if(v == "+") num3 = num1 + num2;
                else if(v == "-") num3 = num2 - num1;
                else if(v == "*") num3 = num1 * num2;
                else num3 = num2 / num1;
            }
            else num3 = stoi(v);
            my_stack.push(num3);
        }
        return my_stack.top();
    }
};
