#include <iostream>
#include <sstream>
using namespace std;

int parseAndEval(string s){
    stringstream ss(s);
    int a,b; char op;
    ss >> a >> op >> b;
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default: return 0;
    }
}

int main(){
    string expr="3+4";
    cout << parseAndEval(expr) << endl;
}
