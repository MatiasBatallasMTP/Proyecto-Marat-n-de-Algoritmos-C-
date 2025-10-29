#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    return 0;
}

int evaluate(const string& s) {
    stack<int> values;
    stack<char> ops;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        else if(isdigit(s[i])){
            int val = 0;
            while(i<s.size() && isdigit(s[i])) val = val*10 + (s[i++]-'0');
            i--;
            values.push(val);
        }
        else if(s[i]=='(') ops.push(s[i]);
        else if(s[i]==')'){
            while(ops.top()!='('){
                int b=values.top(); values.pop();
                int a=values.top(); values.pop();
                char op=ops.top(); ops.pop();
                values.push(applyOp(a,b,op));
            }
            ops.pop();
        }
        else {
            while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){
                int b=values.top(); values.pop();
                int a=values.top(); values.pop();
                char op=ops.top(); ops.pop();
                values.push(applyOp(a,b,op));
            }
            ops.push(s[i]);
        }
    }
    while(!ops.empty()){
        int b=values.top(); values.pop();
        int a=values.top(); values.pop();
        char op=ops.top(); ops.pop();
        values.push(applyOp(a,b,op));
    }
    return values.top();
}

int main() {
    string expr = "(2+3)*(4-1)";
    cout << "Resultado: " << evaluate(expr) << endl;
}
