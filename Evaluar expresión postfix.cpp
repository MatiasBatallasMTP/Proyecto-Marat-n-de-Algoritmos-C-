#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evalPostfix(const string& expr) {
    stack<int> s;
    for(char c : expr) {
        if(isdigit(c)) s.push(c-'0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if(c=='+') s.push(a+b);
            else if(c=='-') s.push(a-b);
            else if(c=='*') s.push(a*b);
            else if(c=='/') s.push(a/b);
        }
    }
    return s.top();
}

int main() {
    string postfix = "23*4+";
    cout << "Resultado: " << evalPostfix(postfix) << endl;
}
