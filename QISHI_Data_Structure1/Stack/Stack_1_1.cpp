#include <iostream>
using namespace std;
bool isComplete(string s);

int main() {
    string s1 = "(())()";
    string s2 = "))((";
    string s3 = "()(";
    string s4 = "())";
    string s5 = ")()";
    string s6 = "(()";

    cout << s1 << ": " << isComplete(s1) << endl;
    cout << s2 << ": " << isComplete(s2) << endl;
    cout << s3 << ": " << isComplete(s3) << endl;;
    cout << s4 << ": " << isComplete(s4) << endl;
    cout << s5 << ": " << isComplete(s5) << endl;
    cout << s6 << ": " << isComplete(s6) << endl;

    return 0;
}

bool isComplete(string s){
    int count = 0;
    for(auto c : s){
        if(c == ')' && count == 0) return false;
        if(c == ')') count--;
        else count++;
    }
    return count == 0 ? true : false;
}
